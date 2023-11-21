#include <stdlib.h>
#include <stdio.h>

// funções importantes

void exch(int *a, int *b) {

    int tmp = *a;
    *a=*b;
    *b=tmp;

}

// implementando um merge sort

void merge (int *v, int l, int r1, int r2) {

    int *v2 = malloc(sizeof(int) * (r2-l+1));
    int k = 0; // vai percorrer os os elementos do novo vetor
    int i = l; // vai percorer os elementos do primeiro vetor
    int j = r1+1; // vai percorrer os elementos do segundo vetor

    while (i <= r1 && j <= r2) {

        if (v[i] < v[j] )
            v2[k++] = v[i++];
        else {
            v2[k++] = v[j++];
        }
    } 

    while (i <= r1) 
        v2[k++] = v[i++];
    

    while (j <= r2)
        v2[k++] = v[j++];

    // Agora copiar os elementos de v2 para v

    k = 0;
    for (int i = l; i <= r2; ++i) 
        v[i] = v2[k++];

    free(v2); // liberar o espaço ocupado por v2

}

void mergesort (int *v, int l, int r) {

    if (l >= r) return;
    int meio = (l+r) / 2;
    mergesort(v,l,meio);
    mergesort(v,meio+1,r);
    merge(v,l,meio,r);

}


int main(){

    int n;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i<n; i++) scanf("%d", &vet[i]);

    mergesort(vet,0,n-1);

    for (int i = 0; i<n; i++)
        printf("%d ", vet[i]);

}
