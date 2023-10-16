#include <stdio.h>
#include <ctype.h>

int sum = 0;

long long int soma(long long int n){

    if ( n != 0) {

        sum += n % 10;
        n /= 10;
        soma(n);

    }

    return sum;

}

int main(){

    long long int n;
    scanf("%lld", &n);

    printf("%lld\n", soma(n));

}