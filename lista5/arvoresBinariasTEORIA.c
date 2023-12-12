/*

    GERAL   

    Árvores: São uma coleção não vazia de vértices e arestas
    que satisfazem um conjunto de requerimentos.

    Vértice: é um objeto simples (pode ser chamado de nó), pode
    ter NOME e carrega informações associadas a ele

    Arestas: é uma conexão entre dois vértices;
    Um caminho na árvore é uma lista de vértices distintos que estão
    conectados por arestas na árvore

    Uma árvore tem apenas um caminho que conecta dois vértices

*/

#include <stdlib.h>
#include <stdio.h>

typedef int Item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}


// declarando árvore binária
typedef struct node {
    Item item;
    struct node *esq;
    struct node *dir;
} node;

/*

    Percorrendo uma árvore;

    inorder: nó esquerdo, raiz, nó direito

    preorder: raiz, nó esquerdo, nó direito

    posorder: nó direito, nó esquerdo, raiz

*/

node *new(Item item, node *esq, node *dir) {

    node *novo = malloc(sizeof(node));
    novo->item = item;
    novo->esq = esq;
    novo->dir = dir;

    return novo;

}

void percorre(node *h) {

    if (h == NULL) return;
    printf("%d\n", (h->item));
    percorre(h->esq);
    percorre(h->dir);

}

node *insert(node *h, Item item) {

    Item tmp = h->item;
    Item v = item;

    if(h == NULL) return new(item, NULL, NULL);

    if(less(v,tmp))
        if (h->esq == NULL)
            h->esq = new(item,NULL,NULL);
        else
            insert(h->esq, item);
    else {
        if(h->dir == NULL)
            h->dir = new(item,NULL,NULL);
        else
            insert(h->dir, item);
    }

    return h;

}

Item search(node *h, int v) {
    
    if (h == NULL) return 0;

    Item t = h->item;

    if (v == t) return h->item;
    if (less(v,t)) return search(h->esq, v);
    else return search(h->dir, v);

} 

int main(void) {

    node *teste = new(10,NULL,NULL);
    insert(teste, 5);
    insert(teste, 6);
    insert(teste, 7);
    insert(teste, 4);
    insert(teste, 3);

    percorre(teste);

    printf("\n%d\n", search(teste,11));

}

















