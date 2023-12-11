/*

    O que é uma fila de prioridade?


    -> API de fila de prioridades crescente
    -> API de fila de prioridades descrescente

*/

// implementando com vetores

// Estrutura báscia de um fila com prioridade [vetores]
typedef struct {
    char nome[20];
    int chave;
} Item;

typedef struct {
    Item *v;
    int n, tamanho;
} FP;

typedef FP * p_fp;

//função para realizar troca
void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

// função para criar fila de prioridade com vetor
p_fp criar_filaprio (int tam) {
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam*sizeof(Item));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

// função para inserir elementos nessa fila
void insere (p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
}

// função para extrair o maior número
Item extrai_maximo(p_fp fprio) {

    int j, max = 0;
    for (j=1; j <fprio->n; ++j)
        if (fprio->v[max].chave < fprio->v[j].chave)
            max = j;
        exch(&(fprio->v[max]), &(fprio->v[fprio->n-1]));
        fprio->n--;
        return fprio->v[fprio->n];
}

/*

    HEAP um tipo de árvore binária para implementar fila de prioridades 
    de maneira eficiente

    -> HEAP decrescente : máximo no topo
    -> HEAP crescente : mínimo no topo

    ** Propriedade da HEAP descrescente : o Item de qualquer nó é menor
    ou igual que o Item do pai
    ** Propriedade da HEAP crescente : o Item de qualquer nó é maior ou
    igual que o Item do pai

*/


// implementando [da HEAP para um vetor]

/*

    O índice [0] não é utilizado;
    Os dois filhos de um nó no índice K são respectivamente, 2K e 2K+1;
    Reciprocamente, o pai de qualquer índice K é min(K/2);


*/

// definindo macros

//typedef int Item;

#define Key(A) (A)

#define less(A,B) (Key(A) < Key(B))

//#define exch(A,B) {Item t = A; A=B; B=t;}

// arrumar um elemento de uma árvore decrescente (de baixo para cima)
void fixUp (/*Item*/ int *v, int k) {

    while ( k > 1 && less(v[k/2],v[k])) {
        exch(&v[k/2],&v[k]);
        k/=2;
    }

}

//arrumar um elemento de uma árvore decrescente (de cima para baixo)
void fixDown (int *v, int k, int tam) {

    int j;
    while (2*k <= tam){
        j=2*k;
        if (j < tam && less(v[j],v[j+1])) j++;
        if(!less(v[k],v[j])) break;
        exch(v[k],v[j]);
        k = j;
    }

}






















