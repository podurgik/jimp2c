#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "gen.h"

int main(int argc, char **argv) {
        int i;
	int l=atoi(argv[1]);
	matrix_t * m = wczytaj("matryca.txt");
        matrix_t *m2=malloc(sizeof(matrix_t));
        m2->tab=(int*) malloc(sizeof(int)* m->n); 
	for(i=0;i<l;i++) {	
		gen(m, m2);
		drukuj(m);
		move(m, m2);
		printf("\n");
	}
        printf("\n\nKolumn: %i\nWierszy:%i\nZnakow: %i", m->cols, m->rows, m->n);

        return EXIT_SUCCESS;
}

