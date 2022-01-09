#include "Vector.h"

#include <stdlib.h>
#include <string.h>

struct Vector *create_vector(size_t cell_size, size_t initial_memory)
{
    struct Vector *rv = malloc(sizeof(struct Vector));

    if (initial_memory = 0)
    {
        perror("Vector: size 0");
        exit(1);
    }

    rv->arr = malloc(cell_size * initial_memory);
    rv->cell_size = cell_size;
    rv->memory = initial_memory;
    rv->size = 0;

    return rv;
}

void add_to_vector(struct Vector *v, void *cell)
{
    if (v->size == v->memory)
    {
        v->memory += 10;
        v->arr = realloc(v->arr, v->memory * v->cell_size);
    }

    char *aux = v->arr;
    void *loc = aux + (v->size * v->cell_size);
    memcpy(loc, cell, v->cell_size);
    ++v->size;

    free(cell);
    cell = loc;
}

void *get_element(struct Vector *v, size_t index)
{
    if (index > v->size)
    {
        fprintf(stderr, "Vector: index(%d) greater then size (%d)", index, v->size);
        exit(1);
    }
    char *aux = v->arr;

    return aux + (index * v->cell_size);
}

void free_vector(struct Vector *v)
{
    free(v->arr);
    free(v);
}