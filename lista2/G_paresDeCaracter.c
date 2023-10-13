#include <stdio.h>
#include <string.h>

int n = 0, aux = 2, par = 0, prox = 1;

int pares(char str[201]){

   //printf("palavra: %s\n", str);

    if (str[n] != '\0') {
      if (str[n] != str[aux]) {
            if (str[aux] == '\0') {
              prox++;
              aux = prox;
              n++;
              pares(str);
            }
            aux++;
            pares(str);
      } else if (str[n] == '0') {
            n++;
            pares(str);
      } else if (str[n] == str[aux] && (aux >= n+2)) {
            par++;
            str[aux] = '0';
            str[n] = '0';
            n++;
            prox++;
            aux = prox;
            pares(str);
      } 

    }

   return par;

}


int main(){

    char word[201];
    scanf("%s", word);

    printf("%d\n", pares(word));


}