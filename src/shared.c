#include "shared.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector *variable_table_list, *function_table_list;

void initiate_scope()
{
    variable_table_list = create_vector(sizeof(struct Vector), 10);
    function_table_list = create_vector(sizeof(struct Zap_Function_Declaration), 10);
    // printf("VAR LIST MEMORY %d\n", variable_table_list->memory);
    struct Vector *global_scope = create_vector(sizeof(struct Zap_Variable), 10);
    // printf("GLOBAL SCOPE MEMORY %d\n", global_scope->memory);
    add_to_vector(variable_table_list, global_scope);
}

float a2tof(const char *integer_part, const char *fractional_part)
{
    float rv = (float)atoi(integer_part);

    float power10 = 10;
    const char *c = fractional_part;

    while (*c != '\0')
    {
        rv += (*c - '0') / power10;
        c = c + 1;
        power10 *= 10;
    }

    return rv;
}

struct Zap_Variable *get_variable(const char *name)
{
    // printf("in get_variable\n");
    size_t i = variable_table_list->size;
    do
    {
        --i;
        struct Vector *scope = get_element(variable_table_list, i);
        // printf("scope location = %d\n", scope);

        for (size_t j = 0; j < scope->size; ++j)
        {
            struct Zap_Variable *scope_var = get_element(scope, j);

            if (strcmp(scope_var->name, name) == 0)
                return scope_var;
        }
    } while (i > 0);
    // printf("out get_variable\n");
    return NULL;
}

void run_zap_assignation(struct Zap_Assignation *item)
{
    struct Zap_Variable *var = get_variable(item->name);

    if (var == NULL)
    {
        fprintf(stderr, "Variable \"%s\" is not declared\n", item->name);
        exit(1);
    };

    struct Zap_Value *calculated_value = calculate_zap_expression(item->expr);

    if (var->val->val_type != calculated_value->val_type)
    {
        calculated_value = convert_variable_value(calculated_value, var->val->val_type); // !! some memory issues here 100%
    }
    var->val = calculated_value;
}

void add_variable_to_current_scope(struct Zap_Variable *var)
{
    // printf("in add_variable_to_current_scope\n");
    struct Vector *current_scope = get_element(variable_table_list, variable_table_list->size - 1);
    // printf("current scope location = %d\n", current_scope);
    //  for (size_t i = 0; i < current_scope->size; ++i)
    //  {
    //      struct Zap_Variable *current_scope_var = get_element(current_scope, i);

    //     if (strcmp(current_scope_var->name, var->name))
    //     {
    //         fprintf(stderr, "Variable \"%s\" already defined in current scope.\n", var->name);
    //         exit(1);
    //     }
    // }

    add_to_vector(current_scope, var);

    // printf("out add_variable_to_current_scope\n");
}

void run_zap_init_declaration(struct Zap_Init_Declaration *item, enum Zap_Variable_Type val_type, bool is_const)
{
    // printf("run_zap_init_declaration\n");
    struct Zap_Variable *var = get_variable(item->name);

    if (var != NULL)
    {
        fprintf(stderr, "Variable \"%s\" already defined.\n", var->name);
        exit(1);
    }
    // printf("item name = ");
    // printf("%s\n", item->name);
    var = create_zap_variable(item->name, create_zap_value(NULL, val_type), is_const, item->size);
    add_variable_to_current_scope(var);
    // printf("var name in run_zap_init_declaration = ");
    // printf("%s\n", var->name);
    struct Zap_Assignation *current_assignation = create_zap_assignation(var->name, item->expr);

    run_zap_assignation(current_assignation);
}

void run_zap_declaration(struct Zap_Declaration *item)
{
    // printf("size = ");
    // printf("%d\n", item->declaration_list->size);
    for (size_t i = 0; i < item->declaration_list->size; ++i)
    {
        // printf("sooon decl\n");
        struct Zap_Init_Declaration *decl = get_element(item->declaration_list, i);
        // printf("decl made %s %d\n", decl->name, decl->size);

        run_zap_init_declaration(decl, item->val_type, item->is_const);
    }
}

bool calculate_condition(struct Zap_Expression *condition)
{
    return *(bool *)(convert_variable_value(calculate_zap_expression(condition), Boolean)->val);
}

struct Zap_Signal *run_zap_selection_statement(struct Zap_Selection_Statement *item)
{
    bool condition_truth = calculate_condition(item->condition);

    if (condition_truth)
        return run_zap_block_item_list(item->if_true);

    if (item->if_false != NULL)
        return run_zap_block_item_list(item->if_false);

    return create_zap_signal(Nothing_Signal, NULL);
}

struct Zap_Signal *run_zap_iteration_statement(struct Zap_Iteration_Statement *item)
{
    switch (item->iteration_type)
    {

    case While_Type:
    {
        bool condition_truth = calculate_condition(item->condition);

        while (condition_truth)
        {
            struct Zap_Signal *rv = run_zap_block_item_list(item->block);

            if (rv->sig_type != Nothing_Signal)
                return rv;

            condition_truth = calculate_condition(item->condition);
        }
        return create_zap_signal(Nothing_Signal, NULL);
    }

    case Do_While_Type:
    {
        struct Zap_Signal *rv = run_zap_block_item_list(item->block);

        if (rv->sig_type != Nothing_Signal)
            return rv;

        return run_zap_iteration_statement(create_zap_iteration_statement(While_Type, item->condition, item->block));
    }

    case Do_Until_Type:
    {
        struct Zap_Expression *not_condition = create_unary_zap_expression(item->condition, negation);

        return run_zap_iteration_statement(create_zap_iteration_statement(Do_While_Type, not_condition, item->block));
    }

    default:
    {
        perror("What type of iteration is this?\n");
        exit(1);
    }
    }

    return create_zap_signal(Nothing_Signal, NULL);
}

struct Zap_Signal *run_zap_block_item(struct Zap_Block_Item *b_item)
{
    struct Zap_Signal *rv = create_zap_signal(Nothing_Signal, NULL);

    //!! assignation and delcaration can have signals too
    //!! so what is above is memory leak
    switch (b_item->item_type)
    {
    case Assignation_Type:
        run_zap_assignation(b_item->item);
        return rv;

    case Declaration_Type:
        run_zap_declaration(b_item->item);
        return rv;

    case Selection_Statement_Type:
        return run_zap_selection_statement(b_item->item);

    case Signal_Statement_Type:
        return b_item->item;

    case Iteration_Statement_Type:
        return run_zap_iteration_statement(b_item->item);

    case Function_Call_Type:
        run_zap_function_call(b_item->item);
        return rv;

    default:
        fprintf(stderr, "I don't know what type of block_item is %d\n", b_item->item_type);
    }

    return rv;
}

void print_all_variables()
{
    printf("\nVariables:\n");

    // printf("-- variable_table_list location = %d\n", variable_table_list);

    for (size_t i = 0; i < variable_table_list->size; ++i)
    {
        // printf("i = %d\n", i);
        struct Vector *scope = get_element(variable_table_list, i);
        // printf("-- global scope location = %d\n", scope);

        for (size_t j = 0; j < scope->size; ++j)
        {
            struct Zap_Variable *scope_var = get_element(scope, j);

            int *aux = scope_var->val->val;
            if (aux == NULL)
            {
                printf("%s NULL, ", scope_var->name);
                continue;
            }
            printf("%s | ", scope_var->name);

            print_zap_value(scope_var->val);
        }

        printf("\n");
    }
    printf("\n");
}

void print_zap_value(struct Zap_Value *val)
{
    switch (val->val_type)
    {
    case Integer:
    {
        int *aux = val->val;
        printf("%d", *aux);
        break;
    }

    case Floating_Point:
    {
        float *aux = val->val;
        printf("%f", *aux);
        break;
    }

    case String:
    {
        char *aux = val->val;
        printf("\"%s\"", aux);
        break;
    }

    case Character:
    {
        char *aux = val->val;
        printf("'%c'", *aux);
        break;
    }

    case Boolean:
    {
        bool *aux = val->val;
        printf("%s", *aux ? "true" : "false");
        break;
    }

    default:
    {
        printf("??unknown??");
        break;
    }
    }
}

struct Zap_Value *get_variable_value(const char *name)
{
    struct Zap_Variable *var = get_variable(name);

    if (var == NULL)
    {
        fprintf(stderr, "Variable \"%s\" not declared yet! \n", name);
        exit(1);
    }

    if (var->val == NULL)
    {
        fprintf(stderr, "Variable \"%s\" not initialized yet!\n", name);
        exit(1);
    }

    return var->val;
}

struct Zap_Signal *run_zap_block_item_list(struct Vector *b_item)
{
    struct Vector *next_scope = create_vector(sizeof(struct Zap_Variable), 10);
    add_to_vector(variable_table_list, next_scope);

    struct Zap_Signal *sig = NULL;

    // printf("now we have %d scopes\n", variable_table_list->size);

    for (size_t i = 0; i < b_item->size; ++i)
    {
        struct Zap_Block_Item *current_block_item = get_element(b_item, i);
        sig = run_zap_block_item(current_block_item);

        if (sig->sig_type != Nothing_Signal)
            break;
    }

    --variable_table_list->size;

    if (sig != NULL)
        return sig;

    return create_zap_signal(Nothing_Signal, NULL);
}

const float my_epsilon = 0.00000000001;

bool float_is_zero(float val)
{
    return abs(val) <= my_epsilon;
}

struct Zap_Value *convert_variable_value(struct Zap_Value *from, enum Zap_Variable_Type to)
{
    struct Zap_Value *rv = create_zap_value(NULL, to);
    switch (to)
    {
    case Integer:
    {
        int *rv_val = malloc(sizeof(int));

        switch (from->val_type)
        {
        case Integer:
        {
            *rv_val = *(int *)from->val;
            break;
        }
        case Floating_Point:
        {
            *rv_val = *(float *)from->val;
            break;
        }
        case String:
        {
            *rv_val = atoi((char *)from->val);
            break;
        }
        case Character:
        {
            *rv_val = *(char *)from->val;
            break;
        }
        case Boolean:
        {
            *rv_val = *(bool *)from->val ? 1 : 0;
            break;
        }

        default:
        {
            free(rv_val);
            rv_val = NULL;
            break;
        }
        }

        rv->val = rv_val;
        break;
    }
    case Floating_Point:
    {
        float *rv_val = malloc(sizeof(float));

        switch (from->val_type)
        {
        case Integer:
        {
            *rv_val = *(int *)from->val;
            break;
        }
        case Floating_Point:
        {
            *rv_val = *(float *)from->val;
            break;
        }
        case Character:
        {
            *rv_val = *(char *)from->val;
            break;
        }
        case Boolean:
        {
            *rv_val = *(bool *)from->val ? 1 : 0;
            break;
        }

        default:
        {
            free(rv_val);
            rv_val = NULL;
            break;
        }
        }

        rv->val = rv_val;
        break;
    }

    case String:
    {
        char *rv_val;

        switch (from->val_type)
        {
        case Integer:
        {
            sprintf(rv_val, "%d", *(int *)from->val);
            break;
        }
        case Floating_Point:
        {
            sprintf(rv_val, "%f", *(float *)from->val);
            break;
        }
        case String:
        {
            rv_val = strdup((char *)from->val);
            break;
        }
        case Character:
        {
            rv_val = malloc(sizeof(char) * 2);
            rv_val[0] = *(char *)from->val;
            rv_val[1] = '\0';
            break;
        }
        case Boolean:
        {
            rv_val = strdup(*(bool *)from->val ? "true" : "false");
            break;
        }

        default:
        {
            rv_val = NULL;
            break;
        }
        }

        rv->val = rv_val;
        break;
    }

    case Boolean:
    {
        bool *rv_val = malloc(sizeof(bool));

        switch (from->val_type)
        {
        case Integer:
        {
            *rv_val = *(int *)from->val;
            break;
        }
        case Floating_Point:
        {
            *rv_val = float_is_zero(*(float *)from->val);
            break;
        }
        case String:
        case Character:
        {
            *rv_val = *(char *)from->val;
            break;
        }
        case Boolean:
        {
            *rv_val = *(bool *)from->val;
            break;
        }
        default:
        {
            free(rv_val);
            rv_val = NULL;
            break;
        }
        }
        rv->val = rv_val;
        break;
    }
    }

    if (rv->val == NULL)
    {
        perror("U made an oopsie! Conversion not possible!\n"); // !! Maybe you can write from what to what...
        exit(1);
    }

    return rv;
}

void add_function(struct Zap_Function_Declaration *decl)
{
    add_to_vector(function_table_list, decl);
}

struct Zap_Function_Declaration *get_function_declaration(const char *name)
{
    struct Zap_Function_Declaration *rv;

    for (size_t i = 0; i < function_table_list->size; ++i)
    {
        rv = get_element(function_table_list, i);
        if (strcmp(rv->name, name) == 0)
            return rv;
    }

    fprintf(stderr, "I couldn't find function \"%s\"\n", name);
    return NULL;
}

void handle_print(struct Vector *expr_list)
{
    for (size_t i = 0; i < expr_list->size; ++i)
    {
        struct Zap_Expression *expr = get_element(expr_list, i);
        print_zap_value(calculate_zap_expression(expr));
        printf(" ");
    }
    printf("\n");
}

void handle_log()
{
    int log_num = time(NULL);
    char log_file_name[30];
    sprintf(log_file_name, "%d.log", log_num);
    FILE *log_file = fopen(log_file_name, "w");

    // printf("-- variable_table_list location = %d\n", variable_table_list);

    char *spaces = malloc(sizeof(char) * 100);
    *spaces = '\0';

    for (size_t i = 0; i < variable_table_list->size; ++i)
    {
        // printf("i = %d\n", i);
        struct Vector *scope = get_element(variable_table_list, i);
        // printf("-- global scope location = %d\n", scope);

        for (size_t j = 0; j < scope->size; ++j)
        {
            struct Zap_Variable *scope_var = get_element(scope, j);
            fprintf(log_file, "%s", spaces);
            if (scope_var->val->val == NULL)
            {
                fprintf(log_file, "%s | NULL, ", scope_var->name);
                continue;
            }
            fprintf(log_file, "%s | ", scope_var->name);

            struct Zap_Value *val = scope_var->val;

            switch (val->val_type)
            {
            case Integer:
            {
                int *aux = val->val;
                fprintf(log_file, "%d", *aux);
                break;
            }

            case Floating_Point:
            {
                float *aux = val->val;
                fprintf(log_file, "%f", *aux);
                break;
            }

            case String:
            {
                char *aux = val->val;
                fprintf(log_file, "\"%s\"", aux);
                break;
            }

            case Character:
            {
                char *aux = val->val;
                fprintf(log_file, "'%c'", *aux);
                break;
            }

            case Boolean:
            {
                bool *aux = val->val;
                fprintf(log_file, "%s", *aux ? "true" : "false");
                break;
            }

            default:
            {
                fprintf(log_file, "??unknown??");
                break;
            }
            }

            fprintf(log_file, "\n");
        }

        strcat(spaces, "    ");
    }
    fprintf(log_file, "\n");

    fclose(log_file);

    printf("logged to %s\n", log_file_name);
}

struct Zap_Value *run_zap_function_call(struct Zap_Function_Call *func_call)
{
    int *rv_val = malloc(sizeof(int));
    *rv_val = 0;
    struct Zap_Value *rv = create_zap_value(rv_val, Integer);
    if (strcmp(func_call->name, "print") == 0)
    {
        handle_print(func_call->argument_list);
    }
    else if (strcmp(func_call->name, "log") == 0)
    {
        handle_log();
    }

    // struct Zap_Init_Declaration *decl = malloc(sizeof(struct Zap_Init_Declaration));

    // struct Zap_Function_Declaration *func_decl = get_function_declaration(func_call->name);

    // if (func_decl->parameter_list->size != func_call->argument_list->size)
    // {
    //     fprintf(stderr, "The number of arguments doesn't match the number of parameters for function \"%s\". \nbIg SaD\n", func_call->name);
    // }

    // printf("aici\n");

    return rv;
}