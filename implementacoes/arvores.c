#include <stdlib.h>
#include <stdio.h>

// Criando a estrutura da árvore com listas
typedef struct tree {
    int dado;
    struct tree *esq;
    struct tree *dir;
} tree;


tree *criar_nova(int dado) {

    tree *nova = (tree*)malloc(sizeof(tree));
    nova->dado = dado;
    nova->esq = NULL;
    nova->dir = NULL;

    return nova;

}

void adicionar(tree *nodo, int dado) {

    // Os elementos menores que a raíz serão adicionados à esquerda
    if (dado < nodo->dado) {
        if (nodo->esq == NULL)
            nodo->esq = criar_nova(dado);
        else
            adicionar(nodo->esq, dado);
    }
    // Os elementos maiores que a raiz serão adicionar à direita
    if (dado > nodo->dado) {
        if(nodo->dir == NULL)
            nodo->dir = criar_nova(dado);
        else
            adicionar(nodo->dir, dado);
    }

}

// Imprimindo os elementos da árvore
void imprimir(tree *nodo) {

    /*
    
        Podemos imprimir os elementos de uma árvore de 3 maneiras
        inorder: direita raiz esquerda
        preorder: raiz esquerda direita
        posorder: esquerda direita raiz

    */

   if (nodo == NULL) return;

    //imprimindo os elementos em preorder
    printf("Elemento: %d\n", nodo->dado);
    imprimir(nodo->esq);
    imprimir(nodo->dir);

}

// Buscar elemento em uma árvore
void busca(tree *nodo, int dado) {

    if (nodo == NULL) return;

    // Caso encontre o elemento
    if (nodo->dado == dado) {
        printf("elemento presente na arvore\n");
        return;
    } 

    // buscando nos ramos da esquerda
    if (dado < nodo->dado) 
        busca(nodo->esq, dado);
    else // buscando nos ramos da direita
        busca(nodo->dir, dado);

}

// Removendo elemento de uma árvore



int main(void) {

    tree *node = criar_nova(10);
    adicionar(node,5);
    adicionar(node,4);
    adicionar(node,2);
    adicionar(node,3);
    adicionar(node,7);
    adicionar(node,6);
    
    imprimir(node);
    busca(node, 7);


}
















