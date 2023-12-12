/*

    Árvores binárias completas e vetores
    elementos 2k e 2k+1;
    raiz v[0];

    MAX HEAP: os filhos são menores que o pai
    MIN HEAP: os filhos são maiores que o pai

*/

#include <stdlib.h>

typedef struct Item {
    char nome[20];
    int chave;
} Item;

typedef struct FP {
    Item *v;
    int n, tamanho;
} FP;

typedef FP * p_fp;

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void insere (p_fp fprio, Item item) {
    
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobeNoHeap(fprio, fprio->n-1);

}

#define PAI(i) ((i-1)/2)

void sobeNoHeap(p_fp fprio, int k) {
    
    if (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave) {
        exch(&fprio->v[k].chave,&fprio->v[PAI(k)].chave);
        sobeNoHeap(fprio, PAI(k));
    }

}

Item extraiMaximo(p_fp fprio) {
    
    Item item = fprio->v[0];
    exch(&fprio->v[0],&fprio->v[fprio->n-1]);
    desceNoHeap(fprio,0);
    return item;
}

#define F_ESQ(i) (2*i+1) // filho esquerdo de i
#define F_DIR(i) (2*i+2) // Filho direito de i

void desceNoHeap(p_fp fprio, int k) {
    
    int maior_filho;

    if (F_ESQ(k) < fprio->n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n && fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave)
            maior_filho = F_DIR(k);
        if (fprio->v[k].chave < fprio->v[maior_filho].chave) {
            exch(&fprio->v[k],&fprio->v[maior_filho]);
            desceNoHeap(fprio, maior_filho);
        }
    }
}

void muda_prioridade(p_fp fprio, int k, int valor) {
    if (fprio->v[k].chave < valor) {
        fprio->v[k].chave = valor;
        sobeNoHeap(fprio, k);
    } else {
        fprio->v[k].chave = valor;
        desceNoHeap(fprio,k);
    }
}

