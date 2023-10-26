#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int empilha (pilha *p, int x) {

    if (p->topo != p->N) {
        p->dados[p->topo] = x;
    } else {
        p->N*=2;
        p->dados = realloc(p->dados,sizeof(int)*p->N);
        p->dados[p->topo] = x;
    }

    p->topo++;
    return 1;


}