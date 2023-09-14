#include <stdio.h>
#include <ctype.h>
#include <string.h>

int minusculo(char letra) {

    if (letra >= 'a' && letra <= 'z') {
        return 1;
    } else return -1;


}

int maiusculo(char letra) {
    
    if (letra >= 'A' && letra <= 'Z'){
        return 1;
    } else return -1;

}


int main(){

    int n,m,a,k;
    int nm = 0,na = 0,nk = 0;
    char string[1001];


    // n se refere a quantidade de caracteres que a senha deve ter
    // m a quantidade de letras minusculas
    // a (a quantidade de letras maisuculas)
    // k a quantidade de números

    scanf("%d %d %d %d", &n, &m, &a, &k);
    scanf("%s", string);

    if (strlen(string) < n) {
        printf("Ufa :)\n");
        return 0;
    }

    for (int i = 0; i < strlen(string); ++i) {
        if (minusculo(string[i]) == 1 ) nm++;
        else if (maiusculo(string[i]) == 1) na++;
        else if (isdigit(string[i]) != 0) nk++;
    }

    if (nm >= m && na >= a && nk >= k ) printf("Ok =/\n");
    else printf("Ufa :)\n");

}