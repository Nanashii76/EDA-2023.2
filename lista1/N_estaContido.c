#include <stdio.h>

int main(){

    int n, a;
    scanf("%d", &n);
    int vet[n+1];
    for (int i = 0; i < n; ++i) scanf("%d", &vet[i]);
    scanf("%d", &a);
    for (int i = 0; i < n; ++i) {
        if (a == vet[i]) {
            printf("pertence\n");
            return 0;
        }
    }

    printf("nao pertence\n");

}