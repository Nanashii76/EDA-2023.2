#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {

    if (le->prox == NULL) printf("NULL\n");
    else {
        le = le->prox;
        while (le != NULL) {
            printf("%d -> ", le->dado);
            le = le->prox;
        }
        printf("NULL\n");
    }
    
}

void imprime_rec(celula *le) {

    if (le->prox == NULL) printf("NULL\n");
    else {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }

}

/*
celula *le;

void create(int A[], int n) {
    int i;
    celula *aux, *last;

    le = (celula*)malloc(sizeof(celula));
    le->dado=A[0];
    le->prox=NULL;
    
    last=le;

    for(i=1;i<n;++i){
        aux=(celula*)malloc(sizeof(celula));
        aux->dado=A[i];
        aux->prox=NULL;

        last->prox=aux;

        last=aux;

    }

}




int main(){

    int A[]={1,2,3};

    create(A,3);
    imprime_rec(le);

}
*/




