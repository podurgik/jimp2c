#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "gen.h"

#ifdef _WIN32
	#include <windows.h>
	void w(unsigned millis) {
		Sleep(millis);
	}

	void czyscEkran(){
		system("cls");
	}
#else
	#include <unistd.h>
	void w(unsigned millis) {
		sleep(millis / 1000);
	}

	void czyscEkran(){
		printf("\033[H\033[J");
	}
#endif

void help(char * name) {
	printf("%s: uzycie: %s [no] [path] [time]\n\tno   - liczba krokow, domyslnie: 10\n\tpath - sciezka z matryca wstepnan\n\ttime - czas przerwy w milisekundach\n", name, name);
}

int main(int argc, char **argv) {
	if (argc > 1) {
		if (argv[1][0] == '?' || argv[1][0] == '-' || argv[1][0] == '/' || argv[1][0] == 'h'){
			help(argv[0]);
			return EXIT_SUCCESS;
		}
	}
	
        int i;
	int l = (argc > 1) ? atoi(argv[1]) : 10;
	char * path = (argc > 2) ? argv[2] :  "matryca.txt";
	
	matrix_t * m = wczytaj("matryca.txt");
        matrix_t * m2 = alokuj(m);
	
	for(i = 1; i <= l; i++) {	
		czyscEkran();
		printf("Stan #%i\n", i);
		drukuj(m);
		if(i == l) zapisz(m, path, i);
		gen(m, m2);
		move(m, m2);
		printf("\n");
		w(1000);
	}
	
	
        /* printf("\n\nKolumn: %i\nWierszy:%i\nZnakow: %i\n", m->cols, m->rows, m->n); */

        return EXIT_SUCCESS;
}

