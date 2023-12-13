#include <stdlib.h>
#include <stdio.h>

/*

    Para realizar uma busca, necessia da ordenação prévia do vetor
    dessa forma temos que:

*/

/*

    A busca binária verifica a existência de um elemento dentro de um 
    array ou vetor por particionamento, considerando sua ordenação, verificamos
    se o valor atual é maior, menor ou igual, para que dessa forma possamos
    estabelecer um novo intervalo de valores

*/

int buscabinaria(int *v, int x, int n) {

    int inicio = -1, fim = n;

    while ( inicio < (fim - 1)) {
        int meio = (inicio+fim) / 2;

        if (v[meio] < x) 
            inicio = meio;
        else if(v[meio] > x)
            fim = meio;
        else return 1;

    }

    return -1;
}