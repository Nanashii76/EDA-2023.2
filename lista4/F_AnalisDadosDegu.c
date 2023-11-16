#include <stdlib.h>
#include <stdio.h>

// funções importantes

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b = tmp;
}

// implementando insertion sort

void insertionsort (long int v[], long int l, long int r) {

    // pivotando o menor elemento
    for (int i = r; i > l; r--) {
        if (v[i] < v[i-1])
            exch(&v[i],&v[i-1]);
    }

    for (int i = l+2; i <= r; ++i) {
        int j = i, tmp = v[j];
        while (tmp < v[j-1]) {
            v[j] = v[j-1];
            --j;
        }
        v[j] = tmp;
    }

}



int main(){

    long int vet[1000000], contador = 1;
    char vetCar[1000000] = {'0'};
    char string[1000000];

    while(scanf("%s", string) != EOF);

    for (long int i = 0; string[i] != '\n'; ++i) {
        for (long int j = i; string[j] != string[j++]; ++j) contador++;
        vet[i] = contador;
    }


}