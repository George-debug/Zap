#include "structures.h"

#include <stdlib.h>

#include "shared.h"

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

struct Zap_Expression *create_zap_expression(enum Expression_Type expr_type, void *handle_carry, void *carry)
{
    struct Zap_Expression *rv = malloc(sizeof(struct Zap_Expression));

    rv->expr_type = expr_type;
    rv->handle_carry = handle_carry;
    rv->carry = carry;

    return rv;
}

struct Zap_Value *calculate_zap_expression(struct Zap_Expression *expr)
{
    switch (expr->expr_type)
    {
    case Unary:
    {
        struct Zap_Expression *child = expr->carry;
        calculate_unary_operator calculate1 = expr->handle_carry;
        return calculate1(calculate_zap_expression(child));
    }

    case Binary:
        struct Zap_Expression *children = expr->carry;
        calculate_binary_operator calculate2 = expr->handle_carry;
        return calculate2(calculate_zap_expression(children), calculate_zap_expression(children + 1));

    case Constant:
        struct Zap_Value *rv_constant = expr->carry;

        print_zap_value(rv_constant);

        return rv_constant;

    case Variable:
        struct Zap_Value *rv_variable = get_variable_value(expr->carry);

        print_zap_value(rv_variable);

        return rv_variable;
    }

    return NULL;
}

struct Zap_Init_Declaration *create_zap_init_declaration(char *name, struct Zap_Expression *expr, size_t size)
{
    struct Zap_Init_Declaration *rv = malloc(sizeof(struct Zap_Init_Declaration));

    rv->name = name;
    rv->expr = expr;
    rv->size = size;

    return rv;
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

struct Zap_Signal *create_zap_signal(enum Zap_Signal_Type sig_type, void *carry)
{
    struct Zap_Signal *rv = malloc(sizeof(struct Zap_Signal));

    rv->sig_type = sig_type;
    rv->carry = carry;

    return rv;
}

struct Zap_Block_Item *create_zap_block_item(void *item, enum Zap_Block_Item_Type item_type)
{
    struct Zap_Block_Item *rv = malloc(sizeof(struct Zap_Block_Item));

    rv->item = item;
    rv->item_type = item_type;

    return rv;
}

struct Zap_Function_Call *create_zap_function_call(char *name)
{
    struct Zap_Function_Call *rv = malloc(sizeof(struct Zap_Function_Call));

    rv->name = name;

    return rv;
}