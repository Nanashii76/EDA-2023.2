#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) printf("THUMS THUMS THUMS\n");
        else printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
    }



}