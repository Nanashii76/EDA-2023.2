#include <stdio.h>
#include <string.h>

char newStr[501];
int aux = 0;

void inverte(char str[501], int tam){

    //printf("string: %s\n", str);

    if (tam >= 0) {
        newStr[aux] = str[tam-1];
        tam--;
        aux++;
        inverte(str,tam);
    } else {
        newStr[aux+1] = '\0';
        printf("%s\n", newStr);
    }

    //printf("%c\n", newStr[aux]);

}



int main(){

    int tam;
    char str[501];

    scanf("%s", str);
    tam = strlen(str);

    inverte(str,tam);

}