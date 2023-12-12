#include <stdlib.h>

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

// implementando um quick sort começando com a função separa

int separa(int *v, int l, int r) {

    int p = v[r]; // pivô
    int aux = l;

    for (int i = l; i < r; ++i) {
        if(v[i] <= p) {
            exch(&v[i],&v[aux]);
            aux++;
        }
    }

    exch(&v[aux],&v[r]);
    return aux;

}

void quicksort(int *v, int l, int r) {

    if (r <= l) return;

    int j = separa(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);

}