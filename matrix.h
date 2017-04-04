#define MAT
typedef struct {
        int cols;
        int rows;
        int n;
        int * tab;
} matrix_t;

matrix_t* wczytaj(char*);
void drukuj(matrix_t*);
int kom(matrix_t*, int, int);
void move(matrix_t*, matrix_t*);
matrix_t * alokuj(matrix_t*);
void zapisz(matrix_t * m, char * path, int nk);
