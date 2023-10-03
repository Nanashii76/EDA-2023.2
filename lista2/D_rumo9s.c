#include <stdio.h>


int multiple (long long n) {

	int aux = 0, a = 1;

	if (n % 9 != 0) return -1;

	if (n != 0) {
		n/=10;
		aux++;

		if (aux == 9) {
			aux = 0;
			a++;
		}

		multiple(n);

	}

	return a;

	
}


int main (){

	long long n;
	scanf("%lld", &n);
	
	while (n != 0) {
	
		if ( multiple(n) != -1){
			printf("%lld is a multiple of 9 and has 9-degree %d.\n", n,multiple(n));
		
		} else printf("%lld is not a multiple of 9\n", n);

		scanf("%lld", &n);

	}


}
