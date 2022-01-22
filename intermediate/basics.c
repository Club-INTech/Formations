#include "basics.h"
#include <stdlib.h>
#include <stdio.h>

c_uint pgcd(c_uint a, c_uint b) {
    if(a < b) {
        c_uint tmp = a;
        a = b;
        b = tmp;
    }
    if(b == 0) {
        return a;
    } else {
        return pgcd(a % b, b);
    }
}

int gray_code(int n) {
    return n ^ (n >> 1);
}

int reverse_gray_code(int n) {
    int res = 0;
    for(; n; n>>=1) {
        res ^= n;
    }
    return res;
}

void is_that_array_sizeof(int a[]) {
    printf("sizeof an array in parameter is %ld\n", sizeof(a));
    printf("sizeof dereferenced array in parameter is %ld\n", sizeof(*a));
}

void experiment_with_sizeof(void) {
    int a[5] = {1, 45, 67, 56, 3};
    int *b = a;
    printf("sizeof an array defined locally is %ld\n", sizeof(a));
    printf("sizeof dereferenced array defined locally is %ld\n", sizeof(*a));
    printf("sizeof pointer assigned to array is %ld\n", sizeof(b));

    printf("And now we call a created method\n");
    is_that_array_sizeof(a);
} 