#include <stdio.h>

int main(){

    int n, a, b = 0;
    scanf("%d", &n);
    int vet[n+1];

    for (int i = 0; i < n; ++i) scanf("%d", &vet[i]);
    a = vet[0];
    for (int i = 1; i < n-1; ++i) {
        if (a > vet[i]){
            a = vet[i];
            b = i;
        } 
    }
    printf("%d\n", b);

}