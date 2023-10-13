#include <stdio.h>
#include <string.h>

int i = 0, j = 0, /*ocorrencias = 0,*/ aux, aux2, vezes = 0;

int qtdSub(char str[101], char sub[101]){

    if ( str[i] == sub[j] && j < strlen(sub) ) {
        if (j == strlen(sub)-1) {
            j = 0, /*ocorrencias++,*/ aux = i;
            if (vezes == 0 && strlen(sub) > 2 ) aux2=i-2, vezes++;
            else if (vezes == 0 && strlen(sub) == 2 ) aux2=i-1, vezes++;
            else if (vezes == 0 && strlen(sub) == 1) aux2=i,vezes++;
            ++i;
            qtdSub(str, sub);
        } 
        ++i;
        ++j;
        qtdSub(str,sub);
    } else if (str[i] != sub[j] && str[i] != '\0') ++i, qtdSub(str,sub);

    //printf("ultima letra: %d\n", aux);
    //printf("primeira letra: %d\n", aux2);
    //printf("ocorrencias: %d\n", ocorrencias);

    return (aux-aux2)+1;

}


int main(){

    char str[101];
    char sub[101];

    scanf("%s", str);
    scanf("%s", sub);

    printf("%d\n", qtdSub(str,sub));


}