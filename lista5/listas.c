#include <stdlib.h>
#include <stdio.h>

// implementando listas encadeadas simples

// Criando uma lista, seu primeiro elemento será sua cabeça
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Criando uma lista simples
celula *nova(int h) {

    celula *novo = (celula*)malloc(sizeof(celula));
    novo->dado = h;
    novo->prox = NULL;

    return novo;

}

// Adicionando
void add(celula *le, int x) {

    if ( le == NULL) {
        le->dado = x;
        le->prox = NULL;
        return;
    } 

    celula *new = (celula*)malloc(sizeof(celula));
    celula *aux = le;

    while (aux->prox != NULL)
        aux = aux->prox;

    new->dado = x;
    aux->prox = new;
    new->prox = NULL;

}

// imprimindo
void imprime(celula *le) {

    if (le == NULL){
        printf("Lista vazia\n");
        return;
    }

    celula *aux = le;

    while (aux != NULL) {
        printf("Dado: %d\n", aux->dado);
        aux = aux->prox;
    }
        

}

// adicionar no inicio
void insere_inicio(celula *le, int x) {

    celula *new = nova(x);
    celula *aux = le->prox;

    le->prox = new;
    new->prox = aux;

}

// buscando

// removendo

// comparando


int main(void) {

    celula *le = nova(0);
    add(le,1);
    add(le,2);
    add(le,3);
    add(le,4);

    insere_inicio(le,10);

    imprime(le);

}


















