#include <stdio.h>
#include <stdlib.h>
#include "gen.h"
#ifndef MAT
#include "matrix.h"
#endif
void middle(matrix_t *m, matrix_t *m2, int i, int j) {
	int neibours=m->tab[m->cols*i+j-m->cols-1]+m->tab[m->cols*i+j-m->cols]+m->tab[m->cols*i+j-m->cols+1]+m->tab[m->cols*i+j-1]+m->tab[m->cols*i+j+1]+m->tab[m->cols*i+j+m->cols-1]+m->tab[m->cols*i+j+m->cols]+m->tab[m->cols*i+j+m->cols+1];
	if(m->tab[m->cols*i+j]==0) {
		if(neibours==3) m2->tab[m->cols*i+j]=1;
		else m2->tab[m->cols*i+j]=0;
	}
	if(m->tab[m->cols*i+j]==1) {
		if(neibours==2||neibours==3) m2->tab[m->cols*i+j]=1;
		else m2->tab[m->cols*i+j]=0;
	}
}

void up(matrix_t *m, matrix_t *m2) {
	int i, neibours;
	for(i=1;i<m->cols-1;i++) {
		neibours=m->tab[i-1]+m->tab[i+1]+m->tab[i+m->cols-1]+m->tab[i+m->cols]+m->tab[i+m->cols+1];
		if(m->tab[i]==0) {
                	if(neibours==3) m2->tab[i]=1;
                	else m2->tab[i]=0;
        	}
        	if(m->tab[i]==1) {
                	if(neibours==2||neibours==3) m2->tab[i]=1;
                	else m2->tab[i]=0;
        	}

	}
}

void down(matrix_t *m, matrix_t *m2) {
	int i, neibours;
        for(i=m->n-2;i>m->n-m->cols;i--) {
        	neibours=m->tab[i-1]+m->tab[i+1]+m->tab[i-m->cols-1]+m->tab[i-m->cols]+m->tab[i-m->cols+1];
		if(m->tab[i]==0) {
                        if(neibours==3) m2->tab[i]=1;
                        else m2->tab[i]=0;
                }
                if(m->tab[i]==1) {
                        if(neibours==2||neibours==3) m2->tab[i]=1;
                        else m2->tab[i]=0;
                }

        }

}

void left(matrix_t *m, matrix_t *m2) {
	int i, neibours;
	for(i=1;i<m->rows-1;i++) {
		neibours=m->tab[m->cols*(i-1)]+m->tab[m->cols*(i-1)+1]+m->tab[m->cols*i+1]+m->tab[m->cols*(i+1)]+m->tab[m->cols*(i+1)+1];
		if(m->tab[m->cols*i]==0) {
                        if(neibours==3) m2->tab[m->cols*i]=1;
                        else m2->tab[m->cols*i]=0;
                }
                if(m->tab[m->cols*i]==1) {
                        if(neibours==2||neibours==3) m2->tab[m->cols*i]=1;
                        else m2->tab[m->cols*i]=0;
                }

	}
}

void right(matrix_t *m, matrix_t *m2) {
	int i, neibours;
        for(i=2;i<m->rows;i++) {
                neibours=m->tab[m->cols*(i-1)-2]+m->tab[m->cols*(i-1)-1]+m->tab[m->cols*i-2]+m->tab[m->cols*(i+1)-2]+m->tab[m->cols*(i+1)-1];
        	if(m->tab[m->cols*i-1]==0) {
                        if(neibours==3) m2->tab[m->cols*i-1]=1;
                        else m2->tab[m->cols*i-1]=0;
                }
                if(m->tab[m->cols*i-1]==1) {
                        if(neibours==2||neibours==3) m2->tab[m->cols*i-1]=1;
                        else m2->tab[m->cols*i-1]=0;
                }

	}
}

void corners(matrix_t *m, matrix_t *m2) {
	int neiboursul=m->tab[1]+m->tab[m->cols]+m->tab[m->cols+1];
	if(m->tab[0]==0) {
                        if(neiboursul==3) m2->tab[0]=1;
                        else m2->tab[0]=0;
                }
                if(m->tab[0]==1) {
                        if(neiboursul==2||neiboursul==3) m2->tab[0]=1;
                        else m2->tab[0]=0;
		}
	int neiboursur=m->tab[m->cols-2]+m->tab[2*m->cols-2]+m->tab[2*m->cols-1];
	if(m->tab[m->cols-1]==0) {
                        if(neiboursur==3) m2->tab[m->cols-1]=1;
                        else m2->tab[m->cols-1]=0;
                }
                if(m->tab[m->cols-1]==1) {
                        if(neiboursur==2||neiboursur==3) m2->tab[m->cols-1]=1;
                        else m2->tab[m->cols-1]=0;
		}
	int neiboursdl=m->tab[m->n-2*m->cols]+m->tab[m->n-2*m->cols+1]+m->tab[m->n-m->cols+1];
        if(m->tab[m->n-m->cols]==0) {
                        if(neiboursdl==3) m2->tab[m->n-m->cols]=1;
                        else m2->tab[m->n-m->cols]=0;
                }
                if(m->tab[m->n-m->cols]==1) {
                        if(neiboursdl==2||neiboursdl==3) m2->tab[m->n-m->cols]=1;
                        else m2->tab[m->n-m->cols]=0;
		}
	int neiboursdr=m->tab[m->n-m->cols-1]+m->tab[m->n-m->cols-2]+m->tab[m->n-2];
	if(m->tab[m->n-1]==0) {
                        if(neiboursdr==3) m2->tab[m->n-1]=1;
                        else m2->tab[m->n-1]=0;
                }
                if(m->tab[m->n-1]==1) {
                        if(neiboursdr==2||neiboursdr==3) m2->tab[m->n-1]=1;
                        else m2->tab[m->n-1]=0;
		}
}

void gen(matrix_t *m, matrix_t *m2) {
	int i, j;
	for(i=1;i<m->cols-1;i++) {
		for(j=1;j<m->rows-1;j++) {
			middle(m, m2, i, j);
		}
	}
	up(m, m2);
	down(m, m2);
	left(m, m2);
	right(m, m2);
	corners(m, m2);
} 
	
