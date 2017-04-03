#include <stdio.h>
#include <stdlib.h>
#ifndef MAT
#include "matrix.h"
#endif

void middle(matrix_t*, matrix_t*, int, int);
void up(matrix_t*, matrix_t*);
void down(matrix_t*, matrix_t*);
void left(matrix_t*, matrix_t*);
void right(matrix_t*, matrix_t*);
void corners(matrix_t*, matrix_t*);
void gen(matrix_t*, matrix_t*);
