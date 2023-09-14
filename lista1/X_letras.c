#include <stdio.h>

int main(){

    float contador = 1, soma=0, jafoi = 0;
    char letra;
    scanf("%c ", &letra);
    
    char string[1001];
    scanf("%[^\n]", string);

    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            contador++;
            jafoi = 0;
        }
        if (string[i] == letra && jafoi == 0) {
            soma++;
            jafoi = 1;
        }
    }

    //printf("%f\n%f\n",soma,contador);
    printf("%.1f\n", (soma/contador)*100);

}