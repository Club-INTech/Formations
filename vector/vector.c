#include "vector.h"
#include <stdlib.h>


void init_vector(vector *vec) {
    vec->capacity = 4;
    vec-> current = 0;
    vec->items = malloc(sizeof(void*) * 4);
}

void *get_element(vector *vec, size_t index){
    if (index >=0 && index <= vec->current) {
        return *(vec->items + index); 
    }
    return NULL;
}

void free_vector(vector *vec) {
    free(vec->items);
}

void push_back_element(vector *vec, void *elem) {
    if(vec->current < vec->capacity) {
        *(vec->items + vec->current) = elem;
    } else {
        size_t tmp_capacity = 2 * vec->capacity;
        vec->items = realloc(vec->items, sizeof(void*) * 2 * tmp_capacity);
        vec->capacity = tmp_capacity;
    }
}