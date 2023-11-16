#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    double x,y;
} ponto;

int main(){

    ponto *p = (ponto *)malloc(sizeof(ponto));

    p->x = 4.5425;
    p->y = 10.2455;

    printf("x cord: %lf\ny cord: %lf\n", p->x, p->y);

}