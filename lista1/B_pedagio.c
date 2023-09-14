#include <stdio.h>

int main(){

    int dist, ped, km, preco, total = 0;
    scanf("%d %d", &dist, &ped);

    scanf("%d %d", &km, &preco);

    total = (dist*km)+((dist/ped)*preco);
    printf("%d\n", total);

}