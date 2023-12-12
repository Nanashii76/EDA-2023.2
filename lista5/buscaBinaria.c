#include <stdlib.h>
#include <stdio.h>

// vetor global que vai ser utilizado como experimento da busca binária
int vet[100];

int buscaBinaria(int vet[], int l, int r, int k) {

    int pivo;
    int cont = 1;

    if (k > vet[r] || k < vet[l]) return -1;

    while (cont) {

        pivo = (l+r)/2;

        if ( k == vet[pivo] ) 
            cont = 0;
        else {
            if ( k < vet[pivo] ) {
                r = pivo-1;
        }   else
                l = pivo+1;
        }
    }

    return vet[pivo];

}

int main(void) {

    int i;

    // criando um vetor que vai de 1 a 100
    for (i = 0; i < 100; i++) 
        vet[i] = i+1;

    printf("%d\n", buscaBinaria(vet,0,i,103));

}