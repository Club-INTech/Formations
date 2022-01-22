#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    vector v;
    init_vector(&v);

    push_back_element(&v, "Hello");
    push_back_element(&v, "World");

    printf("%s is first element\n", get_element(&v, 0));

    free_vector(&v);
    return 0;
}