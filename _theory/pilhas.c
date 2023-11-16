#include <stdio.h>
#include <stdlib.h>

// implementando pilha com listas encadeadas

typedef struct pilha {
    int dado;
    struct pilha *prox;
} pilha;

pilha *p;

// empilhando
void adicionar(int dado) {

    pilha *nova = (pilha *)malloc(sizeof(pilha));
    nova->dado = dado;

    nova->prox = p;
    p = nova;

}

void imprime(){

    pilha *aux = p;

    while (aux != NULL) {
        printf("dado do elemento: %d\n", aux->dado);
        aux = aux->prox;
    }

}

void imprimeRecursivo(pilha *p) {

    if (p != NULL) {
        printf("dado do elemento: %d\n", p->dado);
        imprimeRecursivo(p->prox);
    }

}

void remover() {

    if (p == NULL) printf("operação não realizável\n");
    else {
        p = p->prox;
    }

}

int main(){

    adicionar(5);
    adicionar(15);
    adicionar(25);
    adicionar(35);

    imprimeRecursivo(p);

    remover();

    printf("\n");

    imprimeRecursivo(p);

}







