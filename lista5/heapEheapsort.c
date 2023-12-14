#include <stdlib.h>
#include <stdio.h>

void exch(int *a, int *b) {
    int tmp = *a;
    int *a=*b;
    *b=tmp;
}

typedef int Item;
typedef struct Heap {
    int size;
    Item *v;
} Heap;


Heap *new_Heap(int tam) {

    Heap *new = malloc(sizeof(Heap));
    new->v = malloc(sizeof(Item) * (tam+1));
    new->size = 0;

    return new;

}

void fixUp(Heap *h, int i) {

    while (i > 1 && h->v[i/2] < h->v[i]) {
        exch(&h->v[i/2],&h->v[i]);
        i /= 2;
    }

}

void insert(Heap *h, Item item) {

    h->v[h->size+1] = item;
    h->size++;
    fixUp(h,h->size);

}

void fixDown(Heap *h, int i) {

    int child;
    while(i*2 <= h->size) {
        child = 2*i;
        if(child != h->size && h->v[child] < h->v[child+1])
            child++;

        if(h->v[child] > h->v[i]) {
            exch(&h->v[child],&h->v[i]);
            i = child;
        } else
            break;
    }

}

void pop(Heap *h) {

    exch(&h->v[1],&h->v[h->size]);
    h->size--;
    fixDown(h,1);

}

void heapfy(Heap *h) {

    for(int i = h->size; i > 0; --i)
        fixUp(h,i);
}

int main(void) {

    Item a[] = {4,3,2,1};
    int n = 4; // tamanho do vetor a[]

    /*
    
        Adicionando o vetor à heap e realizando a ordenação por 
        heapsort

    */

    Heap testeHeap;
    testeHeap.v = a-1; // adiciona um espaço vazio no primeiro elemento
    testeHeap.size = n;

    heapfy(&testeHeap);
    while(testeHeap.size != 0)
        pop(&testeHeap);


}