#ifndef OPERATORS_H
#define OPERATORS_H

#include "structures.h"

struct Zap_Value *addition(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *multiplication(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *division(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *reduction(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *modular(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *less(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *less_equal(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *greater(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *greater_equal(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *not_equal(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *equal(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *conjunction(struct Zap_Value *a, struct Zap_Value *b);
struct Zap_Value *disjunction(struct Zap_Value *a, struct Zap_Value *b);

struct Zap_Value *negation(struct Zap_Value *a);
struct Zap_Value *uminus_operator(struct Zap_Value *a);

#endif