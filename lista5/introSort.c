#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A))exch(A,B);}


void heap_sort(Item *v, int l, int r) {
    /*
    pq = v+l-1;

    N = r-l+1;
    for(int k=N/2; k>=1; k--)
        fixDown(k,n);
    while(N>1) {
        exch(pq[1], pq[n]);
        fixDown(1, --N);
    }
    */
}

int separa(int *v, int l, int r) {

    int p = v[r]; // pivô
    int aux = l;

    for (int i = l; i < r; ++i) {
        if(v[i] <= p) {
            exch(v[i],v[aux]);
            aux++;
        }
    }

    exch(v[aux],v[r]);
    return aux;

}

void intro(int *v, int l, int r, int maxdepth) {

    if (r-l <= 15)
        return;

    else if(maxdepth == 0)
        heap_sort(v, l, r);
    else {
        cmpexch(v[l], v[(l+r)/2]);
        cmpexch(v[l], v[r]);
        cmpexch(v[r], v[(l+r)/2]);

        int p = separa(v, l, r);
        intro(v, l, p-1, maxdepth-1);
        intro(v,p+1,r,maxdepth-1);
    }

}

void intro_sort(int *v, int l, int r) {
    
    int maxdepth = 2*((int)log2((double)(r-l+1)));

    intro(v,l,r,maxdepth);
    intro_sort(v,l,r);

}