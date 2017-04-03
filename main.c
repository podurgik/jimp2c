#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "gen.h"

#ifdef _WIN32
	#include <windows.h>
	void w(unsigned millis) {
		Sleep(millis);
	}
#else
	#include <unistd.h>
	void w(unsigned millis) {
		sleep(millis / 1000);
	}
#endif

int main(int argc, char **argv) {
        int i;
	int l=atoi(argv[1]);
	matrix_t * m = wczytaj("matryca.txt");
        matrix_t * m2 = malloc(sizeof(matrix_t));
        m2->tab = (int*) malloc(sizeof(int)* m->n); 
	
	for(i=0;i<l;i++) {	
		printf("\033[H\033[J");
		gen(m, m2);
		drukuj(m);
		move(m, m2);
		printf("\n");
		w(1000);
	}
        //printf("\n\nKolumn: %i\nWierszy:%i\nZnakow: %i\n", m->cols, m->rows, m->n);

        return EXIT_SUCCESS;
}

