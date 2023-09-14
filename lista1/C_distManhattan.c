#include <stdio.h>
#include <stdlib.h>

int main(){

    int mx,my,rx,ry;
    scanf("%d %d %d %d", &mx, &my, &rx, &ry);
    printf("%d\n", abs(rx-mx) + abs(ry-my));

}