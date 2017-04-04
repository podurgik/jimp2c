#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

#ifndef MAT
#include "matrix.h"
#endif

#include "png.h"

void zapiszPNG(const char* filename, const unsigned char* image, unsigned width, unsigned height) {
	/* zapisz */
	unsigned error = lodepng_encode32_file(filename, image, width, height);

	/* jezeli wystapil blad, to wyswietl go */
	if(error) printf("error %u: %s\n", error, lodepng_error_text(error));
}

void setPixel(unsigned char* image, unsigned width, unsigned height, unsigned x, unsigned y, char r, char g, char b, char a) {
	image[4 * width * y + 4 * x + 0] = r;
	image[4 * width * y + 4 * x + 1] = g;
	image[4 * width * y + 4 * x + 2] = b;
	image[4 * width * y + 4 * x + 3] = a;
}

void setAlive(unsigned char* image, unsigned width, unsigned height, unsigned x, unsigned y) {
	unsigned y_max = 10+10*y;
	unsigned x_max = 10+10*x;
	unsigned x_min = x * 10;
	unsigned y_min = y * 10;

	for(y = y_min; y < y_max; y++)
		for(x = x_min; x < x_max; x++) 
			setPixel(image, width, height, x, y, 0, 0, 0, 255);
}

void rysujPNG(matrix_t * m, char * path, int nk) {
	char * filename[50];
	sprintf(filename, "%s_stan_%i.png", path, nk);

	/* generuj obraz */
	unsigned width = m->cols*10, height = m->rows*10;
	unsigned char* image = malloc(width * height * 4);
	unsigned x, y;

		/* zabiel */
	for(y = 0; y < height; y++)
		for(x = 0; x < width; x++)
			setPixel(image, width, height, x, y, 255, 255, 255, 255);

	/* ozyw odpowiednie */
	for(y = 0; y < m->rows; y++)
		for(x = 0; x < m->cols; x++)
			if (kom(m, y, x) == 1) setAlive(image, width, height, x, y);

	zapiszPNG(filename, image, width, height);

	free(image);
}
