#include <stdlib.h>


typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;    
}

// armazenando globalmente os valores

/*
static Item *pq;
static int N;
*/

// armazenando dentro de uma struct
typedef struct pq_st {
    Item *pq;
    int N;
} pq_st;

// inicializar a estrutura heap
void PQinit (pq_st * PQ, int maxN) {

    PQ->pq = malloc(sizeof(Item)*(maxN+1));
    PQ->N = 0;
}

// checar para ver se a fila está vazia
int PQempty(pq_st * PQ) {
    return PQ->N == 0;
}

// arrumar um novo elemento de uma árvore descrescente (de baixo para cima)
void fixUp(int *v, int k) {

    while (k > 1 && less(v[k/2],v[k])) {
        exch(&v[k/2],&v[k]);
        k/=2;
    }
}

// arrumar um determinado elemento de uma árvore decrescente (de cima para baixo)
void fixDown(int *v, int k, int tam) {

    int j;
    while (2*k <= tam) {
        j = 2*k;
        if(j < tam && less(v[j],v[j+1])) j++;
        if(!less(v[k],v[j])) break;
        exch(v[k],v[j]);
        k = j;
    }
}

/*

    OBS: o elemento está sendo adicionado ao final da fila
    a intenção do algotimo do HEAP é justamente quebrar a definição
    para que após a inserção possamos arrumar e organizar os elementos

*/

// adicionando um elemento novo na fila
void PQinsert(pq_st * PQ, Item novo) {

    PQ->pq[++PQ->N] = novo;
    fixUp(PQ->pq, PQ->N);
}

/*

    OBS: Assim como para adicionar um elemento, para remover o maior
    elemento da fila de prioridades iremos novamente quebrar a regra
    primeiro vamos trocar o primeiro elemento (aquele com maior valor)
    com o último elemento(aquele com menor valor), após isso iremos
    utilizar a função fixDown para arrumar nossa árvore, passando como
    tamanho n-1, excluindo assim o maior elemento que tinhamos antes.

*/

// remover o maior item da fila de prioridades
Item PQdelMax (pq_st * PQ) {

    exch(PQ->pq[1],PQ->pq[PQ->N]);
    fixDown(PQ->pq, 1, PQ->N-1);
    return PQ->pq[PQ->N-1];
}


// continuar apenas com o conteúdo acima!!! Rever o de baixo para EDA 2

/*

    Fila de prioridade baseada em índice!
    os valores de PQ->pq serão armazenados fora da struct

    Item *data; -> gerado fora da fila de prioridade, e possui os
    elementos que estão sendo manipulados pelo programa

    Possui definição das funções "less" que sabem comparar os
    elementos do tipo Item

*/

typedef struct pq_ist {
    int N;
    int *pq; // fila de prioridades
    int *qp; // mantém a posição da heap para o elemento de índice k, vai funcionar como uma hash
} pq_ist;

void newExch(pq_ist * PQIST, int i, int j) {
    int t = PQIST->qp[i];
    PQIST->qp[i]=PQIST->qp[j];
    PQIST->qp[j]=t;
    PQIST->pq[PQIST->qp[i]] = i;
    PQIST->pq[PQIST->qp[j]] = j;
}   

void PQISTinit (pq_ist * PQIST, int max) {

    PQIST->N = 0;
    PQIST->pq = malloc(sizeof(int) * (max+1));
    PQIST->qp = malloc(sizeof(int) * (max+1));

}

int PQISTinit (pq_ist * PQIST) {
    return !PQIST->N;
}

void PQISTinsert (pq_ist * PQIST, int k) {

    PQIST->qp[k] = ++PQIST->N;
    PQIST->pq[PQIST->N] = k;
    fixUp(PQIST->pq, PQIST->N);

}

