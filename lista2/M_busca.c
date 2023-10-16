#include <stdlib.h>

typedef struct celula {
    int dado;
    int *prox;
} celula;

// a função iterativa retorna o valor do endereço de memória recebido

    /*
    
        A lista já foi criada com cabeça em le, a partir daí,
        analisamos cada elemento por endereço e comparamos se
        é igual ou não.
    
    */
celula *busca (celula *le, int x) {

    celula *atual = le;
    while ( atual != NULL) {
        if(atual->dado == x) {
            return atual;
        } else {
            atual = atual->prox;
        }
    }

    return atual;

}

// Realizando a mesma função de forma recursiva

celula *busca_rec(celula *le, int x) {

    if (le == NULL) return 0;

    if (le->dado == x) return le;

    return busca_rec(le->prox,x);

}