#include <stdio.h>
#include <stdlib.h>

long int fibonacci(int n) {

    int *aux = &n;
    aux = (long int *) malloc(81);

    if (n == 1 || n == 2) return 1;
    else return *aux=(fibonacci(n-1) + fibonacci(n-2));

}

int main(){
    int n;
    scanf("%d", &n);

    printf("%ld\n", fibonacci(n));
}
