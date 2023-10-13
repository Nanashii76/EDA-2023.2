#include <stdio.h>

int soma = 0, a = 0;

int vetSoma(int vet[1000], int ult) {

    int vet2[1000];

    for (int i = 0; vet[i] != 0; ++i) {
        
        soma += vet[i];

        if (soma > ult) {
            soma = 0;
            vet2[a] = vet[i];
            a++;
            
        }

    }

      for (int i = a-1; i > -1; i--){
        printf("%d\n", vet2[i]);
    }

    return 0;

}



int main(){

    int ult, aux, i = 1;
    int vet[1000];

    scanf("%d", &aux);
    vet[0] = aux;

    while ( aux != 0) {
        scanf("%d", &aux);
        vet[i] = aux;
        ++i;
    }


    scanf("%d", &ult);
    vetSoma(vet,ult);

}