#include <stdlib.h>

typedef struct {
    int *v;
    int N;
    int topo;
} pilha;


void empilha (pilha *p, int x) {

    if (p->topo != p->N) {
        p->v[p->topo] = x;
    } else {
        p->N*=2;
        p->v = realloc(p->v,sizeof(int)*p->N);
        p->v[p->topo] = x;
    }

    p->topo++;

}

int desempilha (pilha *p, int *y) {
    
    if (p->topo == 0) return 0;
    else {
        p->topo--;
        *y = p->v[p->topo];
        return 1;
    }

}