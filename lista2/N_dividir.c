#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void divide_lista (celula *l, celula *l1, celula *l2) {
    
    celula *aux1,*aux2;

    while (l != NULL) {
        if (l->dado % 2 != 0) {
            l1->dado = l->dado;
            l1->prox = NULL;
        } else {
            l2->dado = l->dado;
            l2->prox = NULL;
        }
        l = l->prox;
    }

}