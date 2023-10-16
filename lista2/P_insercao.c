#include <stdlib.h>
#include <stdbool.h>
//#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {

    celula *aux = le->prox;
    celula *novo_le = (celula*)malloc(sizeof(celula));

        le->prox = novo_le;
        novo_le->dado = x;
        novo_le->prox = aux;
    
}

void insere_antes(celula *le, int x, int y) {

    celula *aux = le->prox;
    bool inserido = false;

    while (le->prox != NULL) {
        if ((aux->dado) == y) {
            celula *novo_le = (celula*)malloc(sizeof(celula));
            
            // caso encontre a ocorrência, trocar o valor para true
            inserido = true;

            // Adicionando a nova célula o seu valor correspondente
            novo_le->dado = x;

            // o le->prox agora aponta para o novo le que foi alocado 
            le->prox = novo_le;

            // o novo_le aponta para onde o le->prox estava apontando, por isso uma variável auxiliar
            novo_le->prox = aux;
        } 
        le = aux;
        aux = aux->prox;
    } 

    if (inserido==false) {
         celula *novo_le = (celula*)malloc(sizeof(celula));
         le->prox = novo_le;
         novo_le->dado = x;
         novo_le->prox = NULL;
    }

}


/*
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

    int A[] = {};

    create(A,1);
    insere_inicio(le,4);
    imprime(le);

}
*/