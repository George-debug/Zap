#ifndef SHARED_H
#define SHARED_H

#include "umbrella.h"

void initiate_scope();

float a2tof(const char *integer_part, const char *fractional_part);
bool float_is_zero(float val);

struct Zap_Signal *run_zap_block_item(struct Zap_Block_Item *b_item);
struct Zap_Signal *run_zap_block_item_list(struct Vector *b_item);
struct Zap_signal *run_if_statement();
struct Zap_Value *run_zap_function_call(struct Zap_Function_Call *func_call);

void add_variable_to_current_scope(struct Zap_Variable *var);
void add_function(struct Zap_Function_Declaration *decl);
void run_zap_assignation(struct Zap_Assignation *item);
void run_zap_declaration(struct Zap_Declaration *item);

void print_zap_value(struct Zap_Value *val);
void print_all_variables();
struct Zap_Value *get_variable_value(const char *name);
struct Zap_Value *convert_variable_value(struct Zap_Value *from, enum Zap_Variable_Type to);

#endif