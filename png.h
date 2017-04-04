#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

#ifndef MAT
#include "matrix.h"
#endif

void zapiszPNG(const char* filename, const unsigned char* image, unsigned width, unsigned height);
void setPixel(unsigned char* image, unsigned width, unsigned height, unsigned x, unsigned y, char r, char g, char b, char a);
void setAlive(unsigned char* image, unsigned width, unsigned height, unsigned x, unsigned y);
void rysujPNG(matrix_t * m, char * path, int nk);