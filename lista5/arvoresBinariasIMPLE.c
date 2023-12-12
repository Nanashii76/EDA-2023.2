#include <stdlib.h>
#include <stdio.h>

// definindo macros que provavelmente não serão utilizadas
typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))

// função de troca caso seja necessária
void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

// criando a estrutura da árvore binária
typedef struct node {
    int dado;
    struct node *esq;
    struct node *dir;
} node;

/*
    Definindo funções importante para a árvore
*/

// criando uma nova raiz para a árvore
node *new(int dado) {

    node *novo = (node*)malloc(sizeof(node));
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;

}

// Adicionar um novo elemento à árvore
void add(node *h, int dado) {

   if (dado < h->dado ) {
        if (h->esq == NULL)
            h->esq = new(dado);
        else 
            add(h->esq, dado);
   } else {
        if (h->dir == NULL)
            h->dir = new(dado);
        else
            add(h->dir, dado);
   }

}

// função para percorrer e imprimir os elementos da árvore binára
void imprime(node *h) {

    if (h == NULL) return;

    // imprimindo em preorder

    printf("%d\n", h->dado);
    imprime(h->esq);
    imprime(h->dir);

}

// buscando um elemento sequencialmente e imprimindo
void search(node *h, int n) {

    if (h == NULL) return;

    int t = h->dado;

    if(t == n) printf("\n%d\n", n);
    if(n < t)
        search(h->esq, n);
    else
        search(h->dir, n);

}

// função principal
int main(void) {

    node *novo = new(10);
    add(novo,5);
    add(novo,7);
    add(novo,8);
    add(novo,9);
    add(novo,1);
    add(novo,3);
    add(novo,2);

    imprime(novo);
    search(novo,3);

}

