#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira (fila *f, int *y) {
    y = f->dados[f->p++];
    if (f->p == f->N) {
        f->p = 0;
        f->N--;
        return 0;
    } else return 1;
}


