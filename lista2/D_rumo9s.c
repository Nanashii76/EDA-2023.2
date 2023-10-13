#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aux = 1;

int somaDigs (int n) {
   return (n<10 ? n : (n%10 + somaDigs(n/10)));
}

int grau9 (char str[10001]) {

	aux = 1;

	if (strlen(str) < 2) {
		if (str[0] == '9') return 1;
		else return 0;
	}

	int sum = 0;

	for (int i = 0; i < strlen(str); ++i) sum += str[i] - '0';

	if (sum % 9 != 0) return 0;
	else {
		while (sum != 9) {
		sum = somaDigs(sum);
		aux++;
		} 
	}

	return aux;

}



int main(){

	char str[10001];
	//int sum = 0;

	scanf("%s", str);

	while(str[0] != '0') {

		//for (int i = 0; i < strlen(str); ++i) sum += str[i] - '0';

		if ( grau9(str) != 0 ) printf("%s is a multiple of 9 and has 9-degree %d.\n", str, grau9(str));
		else printf("%s is not a multiple of 9.\n",str);

		//sum = 0;

		scanf("%s", str);

	}


}