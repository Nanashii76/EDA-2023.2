#include <stdio.h>

int main(){

    char string[1001];
    int contador = 0;
    scanf("%s", string);
    for(int i = 0; string[i] != '\0'; ++i) contador++;
    
    char invertido[1001];
    int a=contador-1;

    for(int i = 0; i < contador; ++i ) {
        invertido[i] = string[a];
        a--;
    }

    invertido[contador] = '\0';
    printf("%s\n", invertido);

}