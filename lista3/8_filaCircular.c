#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *v;
    int N;
    int inicio, fim;
} fila;

int enfileira (fila *f, int x) {

    int cap = (f->fim+1)%f->N;

    if (f->v[cap] == f->v[f->inicio]) {
        return 0;
    } else {
       f->v[f->fim] = x;
       f->fim++;
       return 1;
    }

}

int desenfileira (fila *f, int *y) {

    if (f == NULL) {
        return 0;
    } else {
        *y=f->v[f->inicio];
        f->inicio = (f->inicio+1)%f->N;
        return 1;
    }

}