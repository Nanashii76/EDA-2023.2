#include <stdlib.h>
#include <stdio.h>

void merge(int *v, int l, int m, int r) {

    int i = l;
    int j = m+1;
    int k = 0;

    int *aux = malloc(sizeof(int) * (r-l+1));

    while (i <= m && j <= r)
        if(v[i] <= v[j])
            aux[k++]=v[i++];
        else
            aux[k++]=v[j++];
    
    while(i <= m)
        aux[k++]=v[i++];
    
    while(j <= r)
        aux[k++]=v[j++];

    k = 0;

    for (i=l; i<=r; ++i)
        v[i]=aux[k++];

    free(aux);

}

void mergesort(int *v, int l, int r) {

    if (r <= l) return;

    int m = (r+l)/2;
    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);

}

int busca(int *v, int n, int x) {
    int esq = -1, dir = n;

    while (esq < (dir-1)) {
        int meio = (esq+dir)/2;

        if(v[meio] < x)
            esq = meio;
        else if(v[meio] > x)
            dir = meio;
        else return 1;
    }

    return -1;

}

int main(void) {

    int n, index;

    scanf("%d",&n);
    int v[n];
    for(int i = 0; i <n; ++i) scanf("%d", &v[i]);

    mergesort(v,0,n-1);

    while(scanf("%d",&index) != EOF) {
        if(busca(v,n,index) == 1) printf("sim\n");
        else printf("nao\n");
    }

}


