#include <stdio.h>


int calcula (int a, int b, char c) {

    if (c == '+') return a+b;
    else return a-b;

}


int main(){

    int n,a = 0, b = 0, soma = 0, teste = 1;
    scanf("%d", &n);

    int valores[n+1];
    char op[n+1];

    while ( n != 0) {

        for (int i = 0; i < n*2; ++i) {
            if (i % 2 == 0 || i == 0) {
                scanf("%d", &valores[a]);
                a++;
            } else {
                scanf("%c", &op[b]);
                b++;
            }
        }

        a = valores[0];

        for (int i = 0; i < n-1; ++i) {
            soma = calcula(a, valores[i+1], op[i]);
            a = soma;
        }

        printf("Teste %d\n%d\n", teste, soma);
        a = 0;
        b = 0;
        soma = 0;
        teste++;
        scanf("%d", &n);

    }


}