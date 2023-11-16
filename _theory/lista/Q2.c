/*

Projete uma estrutura de dados do tipo fila com duplo encadeamento, ou
seja, cada elemento deve apontar para o próximo elemento e também para o
elemento anterior. Para isso crie uma função de adição de elementos capaz
de inserir elementos nesse formato. Após, crie duas funções, uma para
percorrer os elementos do primeiro até o último, e a outra função para
percorrer os elementos do último até o primeiro.


*/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista {
    int dado;
    struct lista *prox;
    struct lista *ant;
} lista;

lista *list;

void add (int dado) {

    lista *p = (lista *)malloc(sizeof(lista));


    if (list == NULL) {
        list->prox = p;
        p->dado = dado;
        p->ant = list;
        p->prox = NULL;
    } else {

        lista *aux = list;
        while (aux->prox != NULL) aux = aux->prox;

        aux->prox = p;
        p->ant = aux;
        p->prox = NULL;

    }

}

void imprime(lista *l) {

    if (l != NULL) {
        printf("Dado: %d\n", l->dado);
        imprime(l->prox);
    }

}

int main(){

    add(10);
    add(20);
    add(30);

    imprime(list);

}




