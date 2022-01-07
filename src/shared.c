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