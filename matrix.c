#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix_t * wczytaj (char *path){
	FILE * plik = fopen("matryca.txt", "r");

	if (plik == NULL) {
		printf("Brak pliku \"matryca.txt\"!");
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

	plik = fopen("matryca.txt", "r");

	if (plik == NULL) {
		printf("Brak pliku 'matryca.txt'!");
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
	while (i < m->n) {
		printf("%i", m->tab[i++]);
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

void move(matrix_t *m, matrix_t *m2) {
	int i, j;
	for(i=0;i<m->cols;i++) {
		for(j=0;j<m->rows;j++) {
			m->tab[i*m->rows+j]=m2->tab[i*m->rows+j];
		}
	}
}