#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void init_matrix(matrix_wrapper* mw, size_t n, size_t m, matrix mat) {

    for(size_t i=0; i<n; i++) {
        for(size_t j=0; j<m; j++) {
            *(mat + i*m + j) = 2;
        }
    }
    mw->n = n;
    mw->m = m;
    mw->mat = mat;
}

void print_matrix(matrix_wrapper* mw) {
    for(size_t i=0; i<mw->n; i++) {
        for(size_t j=0; j<mw->m; j++) {
            printf("%d ", *(mw->mat + i*mw->m + j));
        }
        printf("\n");
    }
}

void multiply_matrix(matrix_wrapper* res, matrix_wrapper* a, matrix_wrapper* b) {
    if(a->m != b->n || res->n !=a->n || res->m != b->m) {
        printf("Can't multiply matrixes");
        return;
    }
    for(size_t i=0; i<a->n; i++) {
        for(size_t j=0; j<b->m; j++) {
            int sum = 0;
            for(size_t k=0; k<a->m; k++) {
                sum += (*(a->mat + i * a->m + k)) * (*(b->mat + k * b->m + j)); 
            }
        *(res->mat + i * res->m + j) = sum;
        }
    }
}

