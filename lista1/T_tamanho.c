#include <stdio.h>

int main(){

    char string[1001];
    int contador = 0;
    scanf("%s", string);

    for(int i = 0; string[i] != '\0'; ++i) contador++;

    printf("%d\n", contador);

}