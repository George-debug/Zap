#ifndef Vector_H
#define Vector_H

#include <stdio.h>

struct Vector
{
    size_t cell_size, memory, size;
    void *arr;
};

struct Vector *create_vector(size_t cell_size, size_t initial_memory);
void add_to_vector(struct Vector *v, void *cell);
void free_vector(struct Vector *v);
void *get_element(struct Vector *v, size_t index);
void free_vector_cell_destructor(struct Vector *v, void (*destructor)(void *));

#endif