#include <stdlib.h>
#include <stdio.h>

// funções auxiliares

void exch(int *a, int *b) {

    int t = *a;
    *a=*b;
    *b=t;

}


// implementando um bubble sort

void bubblesort (int v[], int l, int r) {

    for (; l < r; r--) {
        for (int i = 0; i < r; ++i) {
            if (v[i] > v[i+1]) 
                exch(&v[i], &v[i+1]);
        }
    }

}

int main(){

     int vet[1001], i = 0;

    while ( scanf("%d", &vet[i]) != EOF ) i++;

    bubblesort(vet, 0, i-1);

    for (int j = 0; j < i; ++j) printf("%d ", vet[j]);
    printf("\n");

}

