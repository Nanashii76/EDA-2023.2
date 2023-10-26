#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira (celula *f, int x) {

    celula *novo = (celula*)malloc(sizeof(celula)), *aux = f->prox;
    novo->dado = x;

    while (aux->prox != f) aux = aux->prox;
    
    aux->prox = novo;
    novo->prox = f;

    return f;

}