#include "structures.h"

#include <stdlib.h>
#include <string.h>

struct Zap_Value *addition(struct Zap_Value *a, struct Zap_Value *b) // !! add const later
{
    printf("facem adunare\n");
    // nu pot interschimba a cu b pentru ca e nevoie de ele si altundeva
    // dar vreau sa: daca am "a" intreg si "b" boolean, sa nu fac si pentru "a" boolean si "b" intreg

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

    printf("left si right facute\n");

    struct Zap_Value *rv; // o valoare e formata dintr-un tip de date si un void* la acea valoare

    switch (left->val_type)
    {
    case Integer: // left este intreg

        switch (right->val_type)
        {
        case Integer: // intreg - intreg
            printf("adunare intreg - intreg\n");
            int *valii = malloc(sizeof(int));

            *valii = *(int *)left->val + *(int *)right->val;

            rv = create_zap_value(valii, Integer);
            break;

        case Floating_Point: // intreg - float
            float *valif = malloc(sizeof(float));

            *valif = *(int *)left->val + *(float *)right->val;

            rv = create_zap_value(valif, Floating_Point);
            break;
        }
        /* alte case-uri daca vrei */

        break;

    case Floating_Point:
        switch (right->val_type)
        {
        case Floating_Point: // float - float | float - intreg avem deja mai sus
            float *valff = malloc(sizeof(float));

            *valff = *(float *)left->val + *(float *)right->val;

            rv = create_zap_value(valff, Floating_Point);
            break;
        }

        break;
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