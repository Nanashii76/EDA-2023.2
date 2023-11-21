#include <stdlib.h>
#include <stdio.h>

// funções importantes

void exch(int *a, int *b) {
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

// implementando um quick sort

// implementando de um jeito rudimentar que precisa de memória extra
int separaBAD(int *v, int l, int r) {
	
	int tam = r-l+1, imenor = 0, imaior = 0;
	int p = v[r];
	int *menores = malloc(sizeof(int)*tam);
	int *maiores = malloc(sizeof(int)*tam);

	for (int i = l; i<r; ++i) {
		if ( v[i] <= p ) 
			menores[imenor++] = v[i];
		else 
			maiores[imaior++] = v[i];
	}

	int cpos = 0;

	for (; cpos < imenor; cpos++)
		v[cpos] = menores[cpos];

    free(menores);

	v[cpos] = p;
	p = cpos;
	cpos++;

	for (int j = 0; j < imaior; ++j)
		v[cpos] = maiores[j];

    free(maiores);

	return p;

}

// implementando um separa Bom

int separa(int *v, int l, int r) {

    int p = v[r];
    int aux = l;

    for (int i = l; i < r; ++i) {
        if (v[i] <= p ) {
            exch(&v[i],&v[aux]);
            aux++;
        }
    }

    exch(&v[aux],&v[r]);
    
    return aux;

}

// versão ingênua do quick sort

void quicksortING(int *v, int l, int r) {

    if (r<=l) return;

    int j = separa(v,l,r);

    quicksortING(v,l,j-1);
    quicksortING(v,j+1,r);

}

// implementando um merge







// implementando um merge sort




int main(){

    int vet[1000], i = 0;

    while (scanf("%d",&vet[i]) != EOF) i++;
    quicksortING(vet,0,i-1);

    for(int j = 0; j < i; ++j) printf("%d ", vet[j]); 

}





















