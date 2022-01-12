#ifndef OPERATORS_H
#define OPERATORS_H

#include "structures.h"

struct Zap_Value *addition(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *multiplication(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *division(struct Zap_Value *a, struct Zap_Value *b);

struct Zap_Value *negation(struct Zap_Value *a);

#endif