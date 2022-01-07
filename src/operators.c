#include "structures.h"

#include <stdlib.h>

struct Zap_Value *addition(struct Zap_Value *a, struct Zap_Value *b)
{
    struct Zap_Value *rv = malloc(sizeof(struct Zap_Value));

    int *a_val = a->val, *b_val = b->val, *rv_val = malloc(sizeof(int));
    *rv_val = *a_val + *b_val;
    rv->val = rv_val;

    return rv;
}