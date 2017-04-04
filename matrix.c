#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix_t * wczytaj (char *path){
	FILE * plik = fopen(path, "r");

	if (plik == NULL) {
		printf("Brak pliku \"%s\"!\n", path);
		exit(1);
	}

	matrix_t * m = malloc(sizeof(matrix_t));

	int znak;
	m->n = 0;
	m->cols = 0;

	while ((znak = fgetc(plik)) != EOF) {
		if (znak != '\n')
			m->n++;
		if (znak == '\n' && m->cols == 0)
			m->cols = m->n;
	}

	m->rows = m->n / m->cols;

	fclose(plik);

	m->tab = (int*) malloc( sizeof(int) * m->n );

	if (m->tab == NULL) {
		printf("Blad alokacji matrycy!");
		exit(1);
	}

	plik = fopen(path, "r");

	if (plik == NULL) {
		printf("Brak pliku \"%s\"!\n", path);
		exit(1);
	}

	int i = 0;
	while ((znak = fgetc(plik)) != EOF) {
		if (znak != '\n') {
			m->tab[i] = (znak == '0') ? 0 : 1;
			i++;
		}
	}

	fclose(plik);
	return m;
}

void drukuj(matrix_t * m) {
	int i = 0;
	int kom;
	while (i < m->n) {
		kom = m->tab[i++];
		/*if (kom == 0) printf("░"); else printf("█");*/
		if (kom == 0) printf("□ "); else printf("■ ");
		/*printf("%i", m->tab[i++]);*/

		if (i % m->cols == 0)
			printf("\n");
	}
}

int kom(matrix_t * m, int wie, int kol) {
	if (wie < m->rows && kol < m->cols)
		return m->tab[wie*m->cols + kol];
	else {
		printf("\nNie ma takiej komorki!");
		exit(2);
	}
}

void move(matrix_t * m, matrix_t * m2) {
	int i;
	for(i=0; i < m->n; i++) {
			m->tab[i] = m2->tab[i];
	}
}

matrix_t * alokuj(matrix_t * m) {
	matrix_t * m2 = malloc(sizeof(matrix_t));
        m2->tab = (int*) malloc(sizeof(int)* m->n);
	m2->n = m->n;
	m2->cols = m->cols;
	m2->rows = m->rows;
	return m2;
}

void zapisz(matrix_t * m, char * path, int nk) {
	char str[50];
	sprintf(str, "%s_stan_%i", path, nk);
	FILE * plik = fopen(str, "w");
	
	int i = 0;
	int kom;
	while (i < m->n) {
		fprintf(plik, "%i", m->tab[i++]);

		if (i % m->cols == 0)
			fprintf(plik, "\n");
	}
	
	fclose(plik);
}
