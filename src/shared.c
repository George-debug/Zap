#include "shared.h"

#include <stdio.h>
#include <stdlib.h>

struct Vector *variable_table_list, *global_scope;

void initiate_scope()
{
    variable_table_list = create_vector(sizeof(struct Vector), 10);
    // printf("VAR LIST MEMORY %d\n", variable_table_list->memory);
    global_scope = create_vector(sizeof(struct Zap_Variable), 10);
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
        perror("Expression has different output! I guess a convertion would work! !!\n");
        exit(1);
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

    print_all_variables();

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

struct Zap_Signal *run_zap_block_item(struct Zap_Block_Item *b_item)
{
    struct Zap_Signal *rv = create_zap_signal(Nothing_Signal, NULL);

    switch (b_item->item_type)
    {
    case Assignation_Type:
        run_zap_assignation(b_item->item);
        return rv;

    case Declaration_Type:
        run_zap_declaration(b_item->item);
        return rv;
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
        int *auxi = val->val;
        printf("value integer = %d\n", *auxi);
        break;

    case Floating_Point:
        float *auxf = val->val;
        printf("value float = %f\n", *auxf);
        break;
    }
}