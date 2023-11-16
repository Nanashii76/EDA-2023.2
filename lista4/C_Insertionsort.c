#include <stdlib.h>
#include <stdio.h>

// funções importantes

void exch(int *a, int *b) {

    int t = *a;
    *a=*b;
    *b=t;

}


// implementando insertion sort (forma ineficiente)

void insertionsortIn (int v[], int l, int r) {

    for(int i = l+1; i <= r; ++i) {
        for(int j = i; j > l; --j) {
            if (v[j] < v[j-1])
                exch(&v[j],&v[j-1]);
        }
    }

}

// implementando insertion sort eficiente

void insertionsort (int v[], int l, int r) {
    
    for(int i = r; i > l; --i)
        if(v[i] < v[i-1]) exch(&v[i],&v[i-1]);
    
    for (int i = l+2; i <= r; ++i) {
        int j = i, tmp = v[j];
        while (tmp < v[j-1] ) {
            v[j] = v[j-1];
            --j;
        }
        v[j] = tmp;
    }

}

int main(){

    int vet[1000000], i = 0;

    while (scanf("%d", &vet[i]) != EOF) i++;
    insertionsort(vet,0,i-1);

    for (int j = 0; j < i; ++j)
        printf("%d ", vet[j]);
    
    printf("\n");

}







