#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef int* matrix;

typedef struct matrix_wrapper {
    size_t n;
    size_t m;
    matrix mat;
} matrix_wrapper;


void init_matrix(matrix_wrapper* mw, size_t n, size_t m, matrix mat);
void print_matrix(matrix_wrapper* mw);
void multiply_matrix(matrix_wrapper*, matrix_wrapper*, matrix_wrapper*);


#endif