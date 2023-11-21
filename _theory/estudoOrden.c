#include <stdlib.h>

// função exchange por referência

void exch(int *a, int *b) {

    int tmp = *a;
    *a=*b;
    *b=tmp;

}

// implementando o selection sort

void selectionsort(int *v, int l, int r) {

    for (int i = l; i < r; ++i) {
        int min = i;
        for (int j = i+1; j < r; ++j)
            if (v[j] < v[min])
                min = j;
        
        if( min != i )
            exch(&v[i],&v[min]);
    }

}

// implementando um bubble sort

void bubblesort(int *v, int l, int r) {

    for (; r > l; --r) {
        for (int i = l; i<r; ++i) {
            if (v[i] > v[i+1])
                exch(&v[i],&v[i+1]);
        }
    }

}

// implementando um bubble sort mais eficiente

void bubblesortEFI(int *v, int l, int r) {

    int swap = 1;

    for (; r > l; --r) {
        for (int i = 0; i < r && swap; ++i) {
            swap = 0;
            if (v[i] > v[i+1]){
                swap = 1;
                exch(&v[i],&v[i+1]);
            }
        }
    }

}

// implemetando um insertion sort

void insertionsort(int *v, int l, int r) {

    // realizando o pivotamento
    for (int i = r; i > l; --i) {
        if (v[i] < v[i-1])
            exch(&v[i],&v[i-1]);
    }

    // após ter o primeiro elemento pivotado, comparar o próxima+1 com os anteriores
    for (int j = l+2; j <= r; ++j) {
        int k = j, tmp = v[k];
        while (tmp < v[k-1]) {
            v[k] = v[k-1];
            --k;
        }
        v[j] = tmp;
    }

}

// implementando um shell sort

void shellsortH(int *v, int l, int r, int h) {

    for (int j = l+h; j <= r; ++j) {
        int k = j, tmp = v[k];
        while (tmp < v[k-h] && k >= l+h) {
            v[k] = v[k-h];
            k -= h;
        } 
        v[j] = tmp;
    }

}

void shellsort(int *v, int l, int r) {

    int h;
    for ( h=1; h <= (r-l)/9; h = 3*h+1);
    for(; h > 0; h = h/3) {
        shellsortH(v,l,r,h);
    }

}

/*

    implementando um quick sort, começando com a função separa

*/

int separa(int *v, int l, int r) {

    int p = v[r];
    int aux = l;

    for (int i = l; i < r; ++i) {
        if (v[i] <= p) {
            exch(&v[i],&v[aux]);
            aux++;
        }
    }

    exch(&v[aux],&v[r]);
    return aux;

}


void quicksort(int *v, int l , int r) {

    if (r <= l) return;

    int j = separa(v,l,r);
    quicksort(v,l,j-1);
    quicksort(v,j+1,r);

}


/*

    Implementando um merge sort começand com a função merge

*/


void merge(int *v, int l, int m, int r) {

    int i = l;
    int j = m+1;

    int *aux = malloc(sizeof(int)*(r-l+1));

    int k = 0;

    while (i<=m && j<=r)
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];

    while ( i <= m)
        aux[k++] = v[i++];

    while ( j <= r)
        aux[k++] = v[j++];
    
    k=0;

    for (i=l; i <= r; ++i ) v[i] = aux[k++];

    free(aux);

}

void mergesort(int *v, int l, int r) {

    if (r <= l) return ;

    int m = (l+r)/2;

    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);

}





