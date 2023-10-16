#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celular *prox;
} celula;

int remove_depois(celula *p) {

    celula *aux = p->prox;
    p->prox = aux->prox;

    return p;

}

void remove_elemento(celula *le, int x){

    celula *aux = le->prox;

    while (le->prox != NULL) {
        if (aux->dado == x) {
            le->prox = aux->prox;
            return;
        }
        le = aux;
        aux = aux->prox;
    }

}

void remove_todos_elementos(celula *le, int x) {
    
    celula *aux = le->prox;

    while (le->prox != NULL) {
        if (aux->dado == x) {
            le->prox = aux->prox;
        } 
        le = aux;
        aux = aux->prox;
    }
}


void imprime(celula *le) {

    if (le == NULL) printf("NULL\n");
    else {
        while (le != NULL) {
            printf("%d -> ", le->dado);
            le = le->prox;
        }
        printf("NULL\n");
    }
    
}

void imprime_rec(celula *le) {

    if (le == NULL) printf("NULL\n");
    else {
        printf("%d -> ", le->dado);
        imprime_rec(le->prox);
    }

}

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

    int A[] = {1,2,20,2,2,3};

    create(A,6);
    remove_todos_elementos(le,2);
    imprime(le);


}
