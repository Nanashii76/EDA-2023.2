#include <stdio.h>

int main(){

    float a,g,ra,rg;
    scanf("%f %f %f %f", &a, &g, &ra, &rg);

    if (a<g) printf("A\n");
    //else if (a == g && ra > rg) printf("A\n");
    else printf("G\n");

}