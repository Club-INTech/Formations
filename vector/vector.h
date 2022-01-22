#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct vector{
    void **items;
    size_t capacity;
    size_t current;
} vector; 


void init_vector(vector *vec);

void *get_element(vector *vec, size_t index);

void free_vector(vector *vec);

void push_back_element(vector *vec, void *elem);


#endif