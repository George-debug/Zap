#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "stdbool.h"
#include "Vector.h"

enum Zap_Variable_Type
{
    Integer,
    Floating_Point,
    String,
    Character,
    Boolean
};

struct Zap_Value
{
    void *val;
    enum Zap_Variable_Type val_type;
};

struct Zap_Value *create_zap_value(void *val, enum Zap_Variable_Type val_type);

struct Zap_Variable
{
    bool is_const;
    char *name;
    struct Zap_Value *val;
    size_t size; // 0 means is just a variable
};

struct Zap_Variable *create_zap_variable(char *name, struct Zap_Value *val, bool is_const, size_t size);

enum Expression_Type
{
    Unary,
    Binary,
    Variable,
    Constant,
    Function_Call
};

struct Zap_Expression
{
    enum Expression_Type expr_type;
    void *handle_carry;
    void *carry;
};

struct Zap_Expression *create_zap_expression(enum Expression_Type expr_type, void *handle_carry, void *carry);

struct Zap_Value *calculate_zap_expression(struct Zap_Expression *expr);

typedef struct Zap_Value *(*calculate_binary_operator)(struct Zap_Value *, struct Zap_Value *);
typedef struct Zap_Value *(*calculate_unary_operator)(struct Zap_Value *);
// typedef struct Zap_Type_Value *(*calculate_function_call)();

struct Zap_Init_Declaration
{
    char *name;
    struct Zap_Expression *expr;
    size_t size;
};

struct Zap_Init_Declaration *create_zap_init_declaration(char *name, struct Zap_Expression *expr, size_t size); // const char... posibil... momentan asa

struct Zap_Declaration
{
    struct Vector *declaration_list;
    enum Zap_Variable_Type val_type;
    bool is_const;
};

struct Zap_Declaration *create_zap_declaration(struct Vector *declaration_list, enum Zap_Variable_Type val_type, bool is_const);

struct Zap_Assignation
{
    char *name;
    struct Zap_Expression *expr;
};

struct Zap_Assignation *create_zap_assignation(char *name, struct Zap_Expression *expr);

struct Zap_Selection_Statement
{
    struct Zap_Expression *condition;
    struct Vector *if_true, *if_false;
};

struct Zap_Selection_Statement *create_zap_selection_statement(struct Zap_Expression *condition, struct Vector *if_true, struct Vector *if_false);

enum Zap_Block_Item_Type
{
    Declaration_Type,
    Assignation_Type,
    Iteration_Statement_Type,
    Selection_Statement_Type,
    Return_Statement_Type,
    Function_Call_Type
};

struct Zap_Block_Item
{
    void *item;
    enum Zap_Block_Item_Type item_type;
};

struct Zap_Block_Item *create_zap_block_item(void *item, enum Zap_Block_Item_Type item_type);

enum Zap_Signal_Type
{
    Return_Signal,
    Continue_Signal,
    Break_Signal,
    Exit_Signal,
    Nothing_Signal
};

struct Zap_Signal
{
    enum Zap_Signal_Type sig_type;
    void *carry;
};

struct Zap_Signal *create_zap_signal(enum Zap_Signal_Type sig_type, void *carry);

struct Zap_Function_Call
{
    char *name; //!!
};

struct Zap_Function_Call *create_zap_function_call(char *name);

#endif