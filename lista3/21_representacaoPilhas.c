#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha (celula *p, int x){

    celula *novo = (celula *)malloc(sizeof(celula));
    
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;

}

int desempilha(celula *p, int *y) {

    celula *aux = p->prox;

    if (p->prox == NULL)
        return 0;
    else {
        *y = p->prox->dado;
        p->prox = aux->prox;
        free(aux);
        return 1;
    }
} 