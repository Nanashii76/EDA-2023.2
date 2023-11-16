#include <stdlib.h>
//#include <stdio.h>

// funções importantes

void exch (int *a, int *b) {
    int t = *a;
    *a=*b;
    *b = t;
}

// implementando

int aux = 0, contador = 0;

void ordena (int *v, int n) {

    if (contador == n) return;

    if (v[n-aux] < v[n-aux-1]) {
        exch(&v[n-aux-1],&v[n-aux]);
        aux++;
        ordena(v,n);
    }

    if (aux == n-contador) {
        contador++;
        aux = 0;
        ordena(v,n);
    }
    
    aux++;
    ordena(v,n);

}

/*
int main(){

    int vet[100000], i = 0;

    while (scanf("%d",&vet[i]) != EOF ) i++;
    ordena(vet,i-1);

    for (int j = 0; j < i; ++j)
        printf("%d ", vet[j]);

}
*/

