#include <stdio.h>
#include <stdlib.h>

// implementando fila

    /*

    criando uma fila de pessoas utilizando listas encadeadas

    */

typedef struct pessoa {
    int id;
    struct pessoa *prox;
} pessoa;

pessoa *fila;

void adicionar (int id) {

    pessoa *p = (pessoa *)malloc(sizeof(pessoa));
    pessoa *aux = fila;

    p->id = id;
    p->prox = NULL;

    if (fila == NULL) {
        fila = p;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = p;
    }

}

void imprime() {

    pessoa *aux = fila;

    while (aux != NULL) {
        printf("id: %d\n", aux->id);
        aux = aux->prox;
    } 

}

void imprimeRecursivo(pessoa *f) {

    if (f != NULL) {
        printf("id: %d\n", f->id);
        imprimeRecursivo(f->prox);
    }
    
}

void remover(){

    if (fila==NULL) printf("operação não realizável\n");
    else {
       fila = fila->prox;
    }

}



int main(){

    adicionar(0);
    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);
    adicionar(5);

    imprime();

    remover();
    remover();

    printf("\n");

    imprime();

    //imprimeRecursivo(fila);

}