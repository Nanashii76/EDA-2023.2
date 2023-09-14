#include <stdio.h>

int main(){

    int a,b,c,x,y,z;
    scanf("%d %d %d", &a, &b, &c);
    a *= b;
    scanf("%d %d %d", &x, &y, &z);
    x *= y;

    z /= c;

    printf("%d\n", (x/a)*z);

}