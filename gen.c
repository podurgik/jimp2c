#include <stdio.h>
#include <stdlib.h>
#include "gen.h"
#ifndef MAT
#include "matrix.h"
#endif

/* f. sprawdzajaca naleznosc do matrycy */
int nal(matrix_t * m, int r, int c) {
	if (r >= 0 && r < m->rows && c >=0 && c < m->cols)
		return 1;
	else
		return 0;
}

int zycie(matrix_t * m, int r, int c) {
	/* licznik sasiadow */
	int sas = 0;
	
	/* zmienne tymczasowe rzedow i kolumn */
	int t_r, t_c;

	t_r = r - 1; t_c = c - 1;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);

	t_r = r - 1; t_c = c;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);
	
	t_r = r - 1; t_c = c + 1;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);

	t_r = r; t_c = c - 1;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);

	t_r = r; t_c = c + 1;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);
	
	t_r = r + 1; t_c = c - 1;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);

	t_r = r + 1; t_c = c;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);

	t_r = r + 1; t_c = c + 1;
	if (nal(m, t_r, t_c))
		sas += kom(m, t_r, t_c);

	
	if (kom(m, r, c) == 1){
		if (sas == 2 || sas == 3)
			return 1;
		else
			return 0;
	} else {
		if (sas == 3)
			return 1;
		else
			return 0;
	}
}


void gen(matrix_t * m, matrix_t * m2) {
	int r, c;
	
	for (r = 0; r < m->rows; r++)
		for (c = 0; c < m->cols; c++)
			m2->tab[r*m->cols + c] = zycie(m, r, c);
}
