#include <stdlib.h>
#include <stdio.h>

void exch(int *a, int *b) {
	int tmp = *a;
	*a=*b;
	*b=tmp;
}

typedef int Item;
typedef struct Heap {
	int size;
	Item *v;
} Heap;


Heap *new_Heap(int tam) {
	
	Heap *new = malloc(sizeof(Heap));
	new->v = malloc(sizeof(Item)*(tam+1));
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
	while (i*2 <= h->size) {
		child = 2*i;
		if (child != h->size && h->v[child] < h->v[child+1])
			child++;

		if (h->v[child] > h->v[i]) {
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

    for (int i = h->size; i > 0; --i)
        fixUp(h,i);

}


int main(void) {

    Item a[] = {4,3,2,1};
    int n = 4;

    // Implementando um Heap sort

    Heap minhaHeap;
    minhaHeap.v = a-1;
    minhaHeap.size = n;

    /*
    
        Para implementar um Heap sort, primeiro temos que adicionar
        a fila de prioridade em uma heap, para isso, foi criado
        uma nova heap que armazena o vet a[], ele foi armazenado
        como a-1, pois dessa forma "deslocamos" o vetor para a direita
        garantindo que o primeiro elemento seja 0;

        após isso, basta dar um heapfy, ou seja, organizar o vetor
        no formato de uma heap e depois dar um pop em cada elemento
        dessa forma estará ordenado com O(N*log(n));

    */

    heapfy(&minhaHeap);
    while(minhaHeap.size != 0)
        pop(&minhaHeap);

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

}