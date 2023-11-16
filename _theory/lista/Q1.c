/*

1) Projete uma estrutura do tipo pilha sequencial de 10 espaços para guardar
informações de páginas da web visitadas. A pilha deve ter uma função para
inserir elementos, remover elementos e exibir os elementos da pilha. Essas
informações estarão contidas na seguinte struct:

struct page {
char address[30];
int connectionType;

};

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct page {
    char address[30];
    int connectionType;
    struct page *prox;
} page;

page *pagina;
int lenght = 0;

void empilhar(page *p, char address[30], int connectionType) {

    if (lenght == 10)
        printf("pilha cheia\n");
    else {
        page *novo  = (page *)malloc(sizeof(page));

        for(int i = 0; address[i] != '\0'; ++i) 
            novo->address[i] = address[i];

        novo->connectionType = connectionType;
        novo->prox = p;
        p = novo;
        lenght++;
    }

}

void desempilhar(page *p) {

    if ( lenght == 0) 
        printf("pilha vazia\n");
    else {
        p = p->prox;
        lenght--;
    }

}

void imprime(page *p) {

    if (p != NULL) {
        printf("Endereço: %s\nConexão: %d\n", p->address, p->connectionType);
        printf("\n");
        imprime(p->prox);
    }
 
}

/*
int main () {

    empilhar(pagina,"teste", 1);
    empilhar(pagina,'tudo bem?', 2);
    empilhar(pagina,'estou otimo!', 3);
    empilhar(pagina,'sim', 4);
    empilhar(pagina,'nao!', 5);
    
    imprime(pagina);

}
*/









