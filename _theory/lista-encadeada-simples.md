## Listas encadeadas simples

-> uma lista encadeada são elementos dispostos cujo endereço de memória
do próximo elemento está guardado com o anterior.


*** código Estudar depois*** 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct livro {
    char nome[200];
    struct livro *prox;
};

struct livro *aloca () {
    return malloc(sizeof(struct livro));
}

int main(){

}