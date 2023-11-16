#include <stdlib.h>
//#include <stdio.h>

// funções importantes

void exch (int *a, int *b) {
    int t = *a;
    *a=*b;
    *b = t;
}

// implementando

int aux = 1, contador = 0;

void ordena (int *v, int n) {

    // caso base de parada
    if (contador >= n) return;

    // ordenando o primeiro elemento do vetor
    if (v[n-aux] < v[n-aux-1] && aux < n-contador) {
        exch(&v[n-aux],&v[n-aux-1]);
        aux++;
        ordena(v,n);
    }

    if (aux >= n - contador) {
        aux = 1;
        contador++;
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

