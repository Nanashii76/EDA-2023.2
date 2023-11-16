#include <stdlib.h>
#include <stdio.h>

// definindo elementos básicos para ordenação

void exch(int *a, int *b) {

    int t = *a;
    *a=*b;
    *b=t;

}

// implementando selection sort

void selectionsort (int vet[], int l, int r) {
  
    for(int i=l; i < r-1; ++i) {
        int min = i;
        for (int j=i+1; j <= r-1; ++j) {
            if (vet[j] < vet[min] ) 
                min = j; 
        }
        if ( i != min)
            exch(&vet[i],&vet[min]); 
    }

}

int main(){

    int i = 0, vet[1001];
    while (scanf("%d",&vet[i]) != EOF) i++;

    selectionsort(vet,0,i);

    for(int j = 0; j < i; ++j) printf("%d ", vet[j]);
    printf("\n");

}

