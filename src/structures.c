#include "structures.h"

#include <stdlib.h>

extern struct Vector *variable_table_list, *global_scope;

struct Zap_Value *create_zap_value(void *val, enum Zap_Variable_Type val_type)
{
    struct Zap_Value *rv = malloc(sizeof(struct Zap_Value));

    rv->val = val;
    rv->val_type = val_type;

    return rv;
}

struct Zap_Variable *create_zap_variable(char *name, struct Zap_Value *val, bool is_const, size_t size)
{
    struct Zap_Variable *rv = malloc(sizeof(struct Zap_Variable));

    rv->name = name;
    rv->val = val;
    rv->is_const = is_const;
    rv->size = size;

    return rv;
}

struct Zap_Expression *create_zap_expression(struct Zap_Value *val, enum Expression_Type expr_type, void *handle_carry, void *carry)
{
    struct Zap_Expression *rv = malloc(sizeof(struct Zap_Expression));

    rv->val = val;
    rv->expr_type = expr_type;
    rv->handle_carry = handle_carry;
    rv->carry = carry;

    return rv;
}

void calculate_zap_expression(struct Zap_Expression *expr)
{
    switch (expr->expr_type)
    {
    case Unary:
        struct Zap_Expression *child = expr->carry;
        calculate_unary_operator calculate1 = expr->handle_carry;
        expr->val = calculate1(child->val);
        break;

    case Binary:
        struct Zap_Expression *children = expr->carry;
        calculate_binary_operator calculate2 = expr->handle_carry;
        expr->val = calculate2(children->val, (children + 1)->val);
        break;

    case Constant:
        expr->val->val = expr->carry;
        break;

    default:
        break;
    }
}

struct Zap_Init_Declaration *create_zap_init_declaration(char *name, struct Zap_Expression *expr, size_t size)
{
    struct Zap_Init_Declaration *rv = malloc(sizeof(struct Zap_Init_Declaration));

    rv->name = name;
    rv->expr = expr;
    rv->size = size;

    return rv;
}

bool var_already_exists(const char *name)
{
    for (size_t i = 0; i < variable_table_list->size; ++i)
    {
        struct Vector *scope = get_element(variable_table_list, i);

        for (size_t j = 0; j < scope->size; ++j)
        {
            struct Zap_Variable *scope_var = get_element(scope, j);

            if (strcmp(scope_var->name, name) == 0)
                return true;
        }
    }
    return false;
}

struct Zap_Variable *add_zap_init_declaration(struct Zap_Init_Declaration *decl)
{
    if (var_already_exists(decl->name))
    {
        fprintf(stderr, "Declaration: Variable %s already exists\n", decl->name);
        exit(1);
    }

    calculate_zap_expression(decl->expr);

    return create_zap_variable(decl->name, decl->expr->val, false, decl->size);
}

struct Zap_Declaration *create_zap_declaration(struct Vector *declaration_list, enum Zap_Variable_Type val_type, bool is_const)
{
    struct Zap_Declaration *rv = malloc(sizeof(struct Zap_Declaration));

    rv->declaration_list = declaration_list;
    rv->val_type = val_type;
    rv->is_const = is_const;

    return rv;
}

struct Zap_Assignation *create_zap_assignation(char *name, struct Zap_Expression *expr)
{
    struct Zap_Assignation *rv = malloc(sizeof(struct Zap_Assignation));

    rv->name = name;
    rv->expr = expr;

    return rv;
}

struct Zap_Block_Item *create_zap_block_item(void *item, enum Zap_Block_Item_Type item_type)
{
    struct Zap_Block_Item *rv = malloc(sizeof(struct Zap_Block_Item));

    rv->item = item;
    rv->item_type = item_type;

    return rv;
}