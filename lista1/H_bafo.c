#include <stdio.h>

int main(){

    int n, rodada = 1, aldo = 0,beto = 0;
    scanf("%d", &n);
    while (n != 0) {

        int a[n+1],b[n+1];

        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a[i],&b[i]);
            aldo += a[i]; 
            beto += b[i];
        }

        if (aldo > beto) printf("Teste %d\nAldo\n", rodada);
        else printf("Teste %d\nBeto\n", rodada);

        aldo = 0;
        beto = 0;
        rodada++;

        scanf("%d", &n);

    }



}