#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira (fila *f, int *y) {

    if (f == NULL) {
        return 0;
    }  
    else {
        *y=f->dados[f->p];
        f->p = (f->p+1)%f->N;
        return 1;
    }

}