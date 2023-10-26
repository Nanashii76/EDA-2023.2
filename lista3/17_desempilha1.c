#include <stdlib.h>
#include <stdbool.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desempilha (celula *p, int *y) {
    celula *aux = p->prox;
    
    if (aux == NULL) {
        return 0;
    } else {
        *y = aux->dado;
        p->prox = aux->prox;
        free(aux);
        return 1;
    }
    
} 