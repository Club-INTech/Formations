#include <stdio.h>
#include <stdlib.h>
#include "basics.h"
#include "matrix.h"

int main() {
	// c_uint res = pgcd((c_uint) 1224, (c_uint) 35350);
	// printf("pgcd of 1224 and 35350 is: %u\n", res);
	// printf("gray code of 22 is: %d\n", gray_code(22));
	// printf("the inverse gray code of 50 is: %d\n", reverse_gray_code(50));

	//experiment_with_sizeof();

	int a[30];
	int b[24];
	int c[20];
	matrix_wrapper wa;
	matrix_wrapper wb;
	matrix_wrapper wc;
	init_matrix(&wa, 5, 6, a);
	init_matrix(&wb, 6, 4, b);
	init_matrix(&wc, 5, 4,c);
	multiply_matrix(&wc, &wa, &wb);
	print_matrix(&wa);
	printf("\n");
	print_matrix(&wb);
	printf("\n");
	print_matrix(&wc);
	printf("\n");
	return 0;
}