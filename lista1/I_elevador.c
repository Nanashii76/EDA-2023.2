#include <stdio.h>

int main(){

    int n, max, ei,e, s, soma=0;
    scanf("%d %d", &n,&max);
    scanf("%d %d", &s, &e);

    ei = e-s;

    for (int i = 0; i < n-1; ++i) {

        scanf("%d %d", &s, &e);
        ei += e-s;
        if (ei > max) soma++;

    }

    if (soma != 0) printf("S\n");
    else printf("N\n");


}