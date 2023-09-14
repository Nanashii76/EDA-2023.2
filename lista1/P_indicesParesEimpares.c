#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int vet[n+1];
    for (int i = 0;i < n; ++i) {
        scanf("%d", &vet[i]);
        if (vet[i] %2 == 0) printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < n ; ++i) {
        if (vet[i] % 2 != 0) printf("%d ", i);
    }

    printf("\n");

}