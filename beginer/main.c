#include <stdio.h>
#include <math.h>

float add_squares(float a, float b) {
    return powf(a, 2.0f) + powf(b, 2.0f);
}


int main() {
    float a;
    float b;
    scanf("%f %f", &a, &b);
    printf("%f\n", add_squares(a, b));
    return 0;
}
