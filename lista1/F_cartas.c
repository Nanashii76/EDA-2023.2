#include <stdio.h>

int main(){

    int vet[5], soma = 0, sub = 0;
    for (int i = 0; i < 5; ++i) scanf("%d", &vet[i]);
    for (int i = 0; i < 5; ++i) {
        if (vet[i] < vet[i+1]) soma++;
        else if (vet[i] > vet[i+1]) sub++;
    }

    if (soma == 4) printf("C\n");
    else if (sub == 4) printf("D\n");
    else printf("N\n");


}