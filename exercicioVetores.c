#include <stdio.h>

int main(int argc, char *argv[]){

    int a,b,*p1,*p2;


    // Passando variáveis por valor
    a = 4;
    b = 3;

    // Passando variáveis por referência
    p1 = &a;
    p2 = p1;

    *p2 = *p1 + 3; // o conteúdo de p2, no caso valor de a, é igual a soma do conteúdo de p1 (que é a) + 3, resultando em 7
    // p2 passa a ser 7, ou seja, a vale 7

    b = b * (*p1); // b passa a ser seu valor original multiplicado pelo conteúdo de p1 (no caso a)
    // b a passa a ser 3 * 7 = 21;
    
    (*p2)++; // é incrementado 1 no conteúdo de p2, no caso passa a ser 8, ou seja a vale 8


    p1 = &b; // p1 recebe o endereço de b;


    printf("%d %d\n", *p1, *p2); // será impresso os conteúdos de p1 = 21 e p2 = 8
    printf("%d %d\n", a, b); // será impresso os valores de a = 8 b = 21;


}