## O que são estrutura de dados e suas diferenças

Estruturas não lineares e lineares
-> Alocação em C
char: 1 byte 
int: 4 bytes
float: 4 bytes
double: 8 bytes

-> Alocação em memória RAM
*** As variáveis podem ser alocadas continuamente, não continuamente, dinamicamente ou estaticamente

*** As variáveis são alocadas na stack, quando o programa demanda mais memória, então alocamos dinamicamente, no heap

-> Estruturas lineares: São aquelas em que elementos estão alocados lado a lado na memória RAM. como Arrays e vetores;
-> Estruturas não-lineares: São aquelas em que os elementos estão espalhados na memória, ou seja, não estão sequenciais.
*** Obs: Para saber onde estão, precisamos guardar seu endereço de memória.


## Linguagem C

****Alocação dinâmica**

#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    double x;
    double y;
} ponto;


int main (){

    ponto *p = (ponto *)malloc(sizeof(ponto));

    p->x = 5.12;
    p->y = 5;

}











