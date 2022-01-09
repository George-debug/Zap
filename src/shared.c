#include "shared.h"

#include <stdio.h>

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

void run_zap_assignation(struct Zap_Assignation *item)
{
}

void run_zap_declaration(struct Zap_Declaration *item)
{
}

struct Zap_Signal *run_zap_block_item(struct Zap_Block_Item *b_item)
{
    struct Zap_Signal *rv = create_zap_signal(Nothing, NULL);

    switch (b_item->item_type)
    {
    case Assignation:
        run_zap_assignation(b_item->item);
        return rv;

    case Declaration:
        run_zap_declaration(b_item->item);
        return rv;
    }

    return rv;
}