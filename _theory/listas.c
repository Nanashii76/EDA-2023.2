#include <stdio.h>
#include <stdlib.h>

// Listas encadeadas

/* 

    Criar uma lista que armazena uma sequência de pontos 
    de um plano 2d


*/

typedef struct ponto {
    double x,y;
    struct ponto *prox;
} ponto;

ponto *listaPontos;
int lenght = 0;

void insereInicio(double x, double y) {

    ponto *p = (ponto *)malloc(sizeof(ponto));
    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;

}

void insereFim(double x, double y) {

    ponto *aux = listaPontos;
    ponto *p = (ponto *)malloc(sizeof(ponto));

    p->x = x;
    p->y = y;
    p->prox = NULL;

    if (listaPontos == NULL) listaPontos->prox = p;

    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = p;
    
}

void insereIndex(int index, double x, double y){

    ponto *p = (ponto *)malloc(sizeof(ponto));
    ponto *aux = listaPontos;

    p->x = x;
    p->y = y;

    if (index>lenght) printf("impossivel realizar operação\n");
    else {
        if (index == 0) {
            p->prox = listaPontos;
            listaPontos = p;
        } else {
            int i = 0;
            while (i!=index-1) {
                aux = aux->prox;
                ++i;
            }
                
            p->prox = aux->prox;
            aux->prox = p;

        }
    }

    lenght++;

}


void imprime(){

    ponto * aux = listaPontos;

    while (aux != NULL) {
        printf("x: %lf\ny: %lf\n", aux->x, aux->y);
        printf("\n");
        aux = aux->prox;
    }

}

void imprimeRecursivo(ponto *aux){
    
    if (aux == NULL) printf("fim\n");
    else {
        printf("x: %lf\ny: %lf\n", aux->x, aux->y);
        printf("\n");
        aux = aux->prox;
        imprimeRecursivo(aux);
    }

}

void removeIndex(int index) {

    ponto *aux = listaPontos;

    if (index>lenght || lenght == 0) printf("Impossivel realizar operação\n");
    else {
        if (index == 0) listaPontos = listaPontos->prox;
        else {
            int i=0;
            while(i<index-1) {
                aux = aux->prox;
                ++i;
            }

            aux->prox = aux->prox->prox;

        }
    }

    lenght--;

}


int main(){

    /*

    insereInicio(5.23, 12.0002);
    insereInicio(6.23, 12.0002);
    insereInicio(7.23, 12.0002);
    insereInicio(8.23, 12.0002);
    insereFim(10,10);
   
    ponto *aux = listaPontos;

    imprime();

    */

   insereIndex(0,1,1);
   insereIndex(1,2,2);
   insereIndex(2,3,3);
   insereIndex(3,4,4);
   insereIndex(3,5,5);
   insereIndex(0,6,6);
   removeIndex(0);

   imprime();

}