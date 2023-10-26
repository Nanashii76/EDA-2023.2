#include <stdlib.h>
#include <stdbool.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

int empilha (celula *p, int x) {
    
    celula *novo = (celula*)malloc(sizeof(celula));

    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;

    return 1;

}