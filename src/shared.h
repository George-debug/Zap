#ifndef SHARED_H
#define SHARED_H

#include "umbrella.h"

void initiate_scope();

float a2tof(const char *integer_part, const char *fractional_part);

struct Zap_Signal *run_zap_block_item(struct Zap_Block_Item *b_item);

void add_variable_to_current_scope(struct Zap_Variable *var);
void run_zap_assignation(struct Zap_Assignation *item);
void run_zap_declaration(struct Zap_Declaration *item);

void print_all_variables();

#endif