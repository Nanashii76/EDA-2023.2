#include <stdio.h>
#include <stdlib.h>

// Construindo a primeira árvore

typedef struct nodo {

    int dado;
    struct nodo *esq;
    struct nodo *dir;

} nodo;


nodo* create (int dado) {

    nodo *n = (nodo *)malloc(sizeof(nodo));
    n->dado = dado;
    n->esq = NULL;
    n->dir = NULL;

    return n;

}

void imprime(nodo *n){

    if (n == NULL)
        return;

    printf("dado: %d\n", n->dado);
    imprime(n->esq);
    imprime(n->dir);

}


void inserir (nodo *n, int dado) {

    if(dado < n->dado) {
        if (n->esq == NULL) 
            n->esq = create(dado);
        else
            inserir(n->esq, dado);
    } else {
        if(n->dir == NULL)
            n->dir = create(dado);
        else
            inserir(n->dir, dado);
    }

}

void remover (nodo *n, int dado) {

    nodo *filho = n;
    nodo *pai;

    do {
        pai = filho;
        if(dado < filho->dado)
            filho = filho->esq;
        else if (dado > filho->dado)
            filho = filho->dir;
    } while (filho != NULL && filho->dado != dado);


    if(filho != NULL) {

        //primeiro caso base quando o pai aponta para NULL

        if(filho->esq == NULL && filho->dir == NULL) 
            if(pai->esq == filho) 
                pai->esq = NULL;
            else
                pai->dir = NULL;
        
        //segundo caso quando há pelo menos 1 filho, seja esq ou dir

        if (filho->esq != NULL && filho->dir == NULL ) {
            if(pai->esq == filho)
                pai->esq=filho->esq;
            else
                pai->dir=filho->dir;
        }


        if (filho->esq == NULL && filho->dir != NULL ) {
            if(pai->esq == filho)
                pai->esq = filho->esq;
            else
                pai->dir = filho->dir;
        }

        //terceiro caso quando o filho tem 2 filhos

        if (filho->esq != NULL && filho->dir != NULL) {
            if(filho->esq->dir == NULL) {
                filho->dado = filho->esq->dado;
            } else {
                nodo *p = filho->esq;
                nodo *aux = p;
                while(p->dir != NULL) {
                    aux = p;
                    p = p->dir;
                }

                aux->dir = NULL;
                filho->dado = p->dado;

            }
        }


    }



}


int main(){


    /*

    nodo *nodo5 = create(5);
    nodo *nodo2 = create(2);
    nodo *nodo1 = create(1);
    nodo *nodo8 = create(8);
    nodo *nodo4 = create(4);

    nodo5->esq = nodo2;
    nodo2->esq = nodo1;
    nodo5->dir = nodo8;
    nodo2->dir = nodo4;    

    imprime(nodo5);

    */

   nodo *n = create(5);
   inserir(n,3);
   inserir(n,2);
   inserir(n,4);
   inserir(n,1);
   inserir(n,8);

   imprime(n);

   printf("\n");

   remover(n,3);

    imprime(n);

}









