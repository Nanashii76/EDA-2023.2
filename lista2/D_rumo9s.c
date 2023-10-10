#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aux = 0;


int somaDigs (int n) {
  return (n<10 ? n : (n%10 + somaDigs(n/10)));
}

int grau9 (int n) {

	int grau;

	if (n == 9) return 1;
	if (n < 9) return 0;
	else {
		grau = grau9(somaDigs(n));
		if (grau > 9) {
			grau = grau9(somaDigs(grau));	
		} 

	}

	return grau+1;

}



int main(){

	char str[10001];
	int sum = 0;

	scanf("%s", str);

	while(str[0] != '0') {

		for (int i = 0; i < strlen(str); ++i) sum += str[i] - '0';

		if ( sum % 9 == 0 ) printf("%s is a multiple of 9 and has 9-degree %d.\n", str, grau9(sum));
		else printf("%s is not a multiple of 9.\n",str);

		sum = 0;

		scanf("%s", str);

	}


}