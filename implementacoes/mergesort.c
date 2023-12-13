#include <stdlib.h>

// primeiro implementar a função merge para separar em subvetores
void merge(int *v, int l, int m, int r) {

    int i = l;
    int j = m+1;
    int k = 0;

    int *aux = malloc(sizeof(int) * (r-l+1));

    while (i <= m && j <= r) {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }

    while (i<= m)
        aux[k++] = v[i++];
    
    while (j <= r)
        aux[k++] = v[j++];

    k = 0;

    for (int i = l; i <=r; ++i)
        v[i] = aux[k++];

    free(aux);

}

// implementando um mergesort
void mergesort(int *v, int l, int r) {

    if (r<=l) return;

    int m = (r-l)/2;

    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);

}