#include "structures.h"
#include "shared.h"

#include <stdlib.h>
#include <string.h>

#include "structures.h"

#include <stdlib.h>
#include <string.h>

struct Zap_Value *uminus_operator(struct Zap_Value *a)
{
    struct Zap_Value *rv = create_zap_value(NULL, a->val_type);
    switch (a->val_type)
    {
    case Integer:
    {
        int *rv_val = malloc(sizeof(int));
        *rv_val = -*(int *)a->val;

        rv->val = rv_val;
        break;
    }
    case Floating_Point:
    {
        float *rv_val = malloc(sizeof(float));
        *rv_val = -*(float *)a->val;

        rv->val = rv_val;
        break;
    }
    }

    if (rv->val != NULL)
        return rv;

    perror("Unary minus doesn't work on that type XD\n");
    exit(1);

    return NULL;
}

struct Zap_Value *addition(struct Zap_Value *a, struct Zap_Value *b) // !! add const later
{
    // printf("facem adunare | %d + %d \n", a->val_type, b->val_type);
    //  nu pot interschimba a cu b pentru ca e nevoie de ele si altundeva
    //  dar vreau sa: daca am "a" intreg si "b" boolean, sa nu fac si pentru "a" boolean si "b" intreg

    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size), *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv; // o valoare e formata dintr-un tip de date si un void* la acea valoare

    switch (left->val_type)
    {
    case Integer: // left este intreg
    {
        switch (right->val_type)
        {
        case Integer:
        { // intreg - intreg
            int *valii = malloc(sizeof(int));

            *valii = *(int *)left->val + *(int *)right->val;

            rv = create_zap_value(valii, Integer);
            break;
        }
        case Floating_Point:
        { // intreg - float
            int *x1 = left->val;
            float *x2 = right->val;
            // printf("adunare %d + %f\n", *x1, *x2);
            float *valif = malloc(sizeof(float));

            *valif = *(int *)left->val + *(float *)right->val;

            // printf("rezultatul este %f\n", *valif);

            rv = create_zap_value(valif, Floating_Point);
            break;
        }
        /* alte case-uri daca vrei */
        case Boolean:
        { /// intreg - bool ??
            break;
        }
        }
        break;
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float | float - intreg avem deja mai sus
            float *valff = malloc(sizeof(float));

            *valff = *(float *)left->val + *(float *)right->val;

            rv = create_zap_value(valff, Floating_Point);
            break;
        }
        }
        break;
    }

    case String:
        switch (right->val_type)
        {
        case String:
        {
            char *rv_val = strdup((char *)left->val);
            strcat(rv_val, (char *)right->val);

            rv = create_zap_value(rv_val, String);
            break;
        }
        }
    }

    // de asta nu returnez direct rv... trebuie free left si right
    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Addition is not possible!\n"); // !! Maaaaybe we can add later between what and what
    exit(1);
    return NULL; // will not reach this point
}

struct Zap_Value *multiplication(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int * int
            int *valii = malloc(sizeof(int));

            *valii = *(int *)left->val * *(int *)right->val;

            rv = create_zap_value(valii, Integer);
            break;
        }
        case Floating_Point:
        { // int * float
            float *valif = malloc(sizeof(float));

            *valif = *(int *)left->val * *(float *)right->val;

            rv = create_zap_value(valif, Floating_Point);
            break;
        }
        case Boolean:
        { // int * bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float * float
            float *valff = malloc(sizeof(float));

            *valff = *(float *)left->val * *(float *)right->val;

            rv = create_zap_value(valff, Floating_Point);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Multiplication is not possible!\n"); // !! Maaaaybe we can add later between what and what
    exit(1);
    return NULL; // will not reach this point
}

struct Zap_Value *division(struct Zap_Value *a, struct Zap_Value *b) // !! add const later
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int / int
            int *valii = malloc(sizeof(int));

            *valii = *(int *)left->val / *(int *)right->val;

            rv = create_zap_value(valii, Integer);
            break;
        }
        case Floating_Point:
        { // int / float
            float *valif = malloc(sizeof(float));

            *valif = *(float *)left->val / *(int *)right->val;

            rv = create_zap_value(valif, Floating_Point);
            break;
        }
        case Boolean:
        { // int * bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float / float
            float *valff = malloc(sizeof(float));

            *valff = *(float *)left->val / *(float *)right->val;

            rv = create_zap_value(valff, Floating_Point);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Division is not possible!\n"); // !! Maaaaybe we can add later between what and what
    exit(1);
    return NULL; // will not reach this point
}

struct Zap_Value *reduction(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));

            *valii = *(int *)left->val - *(int *)right->val;

            rv = create_zap_value(valii, Integer);
            break;
        }
        case Floating_Point:
        { // int -float
            float *valif = malloc(sizeof(float));

            *valif = *(float *)left->val - *(int *)right->val;

            rv = create_zap_value(valif, Floating_Point);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            float *valff = malloc(sizeof(float));

            *valff = *(float *)left->val - *(float *)right->val;

            rv = create_zap_value(valff, Floating_Point);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Reduction is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *modular(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));

            *valii = *(int *)right->val % *(int *)left->val;
            // perror("[operators.c %% Operands are not the same type!");
            rv = create_zap_value(valii, Integer);
            break;
        }
        case Floating_Point:
        { // int -float
            float *valif = malloc(sizeof(float));

            //*valif = *(float *)right->val % *(int *)left->val;
            perror("int %% float? What a madman!");
            // rv = create_zap_value(valif, Floating_Point);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            float *valff = malloc(sizeof(float));

            //*valff = *(float *)right->val % *(float *)left->val;
            perror("float %% float? What a madman!");
            // rv = create_zap_value(valff, Floating_Point);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Modulo is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *less(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val > *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Floating_Point:
        { // int -float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val > *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val > *(float *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Less is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *less_equal(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val >= *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Floating_Point:
        { // int -float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val >= *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val >= *(float *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Less_equal is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *greater(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val < *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Floating_Point:
        { // int -float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val < *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val < *(float *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Great is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *greater_equal(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val <= *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Floating_Point:
        { // int -float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val <= *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val <= *(float *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Great_equal is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *equal(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val == *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Floating_Point:
        { // int -float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val == *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val == *(float *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Equal is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *not_equal(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Integer:
    {
        switch (right->val_type)
        {
        case Integer:
        { // int - int
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val != *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Floating_Point:
        { // int -float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val != *(int *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        case Boolean:
        { // int - bool ??
        }
        }
    }
    case Floating_Point:
    {
        switch (right->val_type)
        {
        case Floating_Point:
        { // float - float
            int *valii = malloc(sizeof(int));
            if (*(float *)left->val != *(float *)right->val)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
        break;
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("NotEqual is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *conjunction(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Boolean:
    {
        switch (right->val_type)
        {
        case Boolean:
        { // bool && bool
            int *valii = malloc(sizeof(int));
            if (*(int *)right->val == 1 && *(int *)left->val == 1)
                *valii = 1;
            else
                *valii = 0;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Conjunction is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *disjunction(struct Zap_Value *a, struct Zap_Value *b)
{
    size_t zap_value_size = sizeof(struct Zap_Value);

    struct Zap_Value *left = malloc(zap_value_size);
    struct Zap_Value *right = malloc(zap_value_size);

    memcpy(left, a, zap_value_size);
    memcpy(right, b, zap_value_size);

    if (left->val_type > right->val_type)
    {
        void *aux = left;
        left = right;
        right = aux;
    }

    struct Zap_Value *rv;

    switch (left->val_type)
    {
    case Boolean:
    {
        switch (right->val_type)
        {
        case Boolean:
        { // bool || bool
            int *valii = malloc(sizeof(int));
            if (*(int *)left->val == 0 && *(int *)right->val == 0)
                *valii = 0;
            else
                *valii = 1;

            rv = create_zap_value(valii, Boolean);
            break;
        }
        }
    }
    }

    free(left);
    free(right);

    if (rv != NULL)
        return rv;

    perror("Disjunction is not possible!\n");
    exit(1);
    return NULL;
}

struct Zap_Value *negation(struct Zap_Value *a)
{
    struct Zap_Value *rv = convert_variable_value(a, Boolean);

    bool *val = rv->val;

    *val = !*val;

    return rv;
}