#include <stdio.h>

int n = 0;

void troca(char str[81]){

    if (str[n] != '\0'){
        if(str[n] == 'x') str[n] = 'y';
        n++;
        troca(str);
    } else {
        printf("%s\n", str);
    }

}



int main(){

    char str[81];
    scanf("%s", str);

    troca(str);
}