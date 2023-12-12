#include <stdlib.h>

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

// implementando um merge sort, começando com a função merge
void merge(int *v, int l, int m, int r) {

    int i = l;
    int j = m+1;

    int *aux = malloc(sizeof(int)*(r-l+1));

    int k = 0;

    while (i<=m && j <=r) 
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];

    while (i<=m)
        aux[k++] = v[i++];

    while(j<=r)
        aux[k++] = v[j++];

    k = 0;

    for (i = l; i <= r; ++i) v[i] = aux[k++];

    free(aux);

}

void mergesort(int *v, int l, int r) {

    if (r <= l) return;

    int m = (l+r)/2;

    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);

}