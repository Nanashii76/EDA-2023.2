#include <stdlib.h>
#include <stdio.h>

typedef struct letras {
    char le;
    int qtd;
    int p;
} letras;

letras l[100001];

// funções importantes

void exch(letras *a, letras *b) {
    letras tmp = *a;
    *a=*b;
    *b = tmp;
}

// implementando bubble sort

void bubblesort(letras let[], int l, int r) {

    for (; l<r; --r) {
        for (int i = 0; i < r; ++i) {
            if (let[i].qtd > let[i+1].qtd) 
                exch(&let[i], &let[i+1]);
        }
    }

 

}

int main(){

    char string[1000000];
    int qtd = 0, contador = 1, aux = 0;

    while(scanf("%s", string) != EOF);

    for(int i = 0; string[i] != '\0'; i++) {
        l[aux].p = i;
        if (string[i] == string[i+1]) {
            l[i].le = string[i];
            while ( string[i] == string[i+1] ) {
                contador++;
                i++;
            }
        } 
               
        l[aux].le = string[i];
        l[aux].qtd = contador; 
        contador = 1;  
        //qtd++; 
        aux++;   
    }

    bubblesort(l,0,aux-1);

    for (int i = 0; i < aux; ++i)
        printf("%d %c %d\n", l[i].qtd, l[i].le ,l[i].p);

}