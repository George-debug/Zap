#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "stdbool.h"
#include "Vector.h"

enum Zap_Variable_Type
{
    Integer,
    Float,
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
    struct Zap_Value *val;
    enum Expression_Type expr_type;
    void *handle_carry;
    void *carry;
};

struct Zap_Expression *create_zap_expression(struct Zap_Value *val, enum Expression_Type expr_type, void *handle_carry, void *carry);

void calculate_zap_expression(struct Zap_Expression *expr);

typedef struct Zap_Value *(*calculate_binary_operator)(struct Zap_Value *, struct Zap_Value *);
typedef struct Zap_Value *(*calculate_unary_operator)(struct Zap_Value *);
// typedef struct Zap_Type_Value *(*calculate_function_call)();

struct Zap_Init_Declaration
{
    char *name;
    struct Zap_Expression *expr, *size;
};

struct Zap_Init_Declaration *create_zap_init_declaration(char *name, struct Zap_Expression *expr, struct Zap_Expression *size); //const char... posibil... momentan asa

struct Zap_Variable *add_zap_init_declaration(struct Zap_Init_Declaration *decl);

#endif