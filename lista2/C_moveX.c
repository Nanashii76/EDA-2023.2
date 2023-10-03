#include <stdio.h>
//#include <string.h>


char printX (int n){

	if (n != 0) {
		printf("x");
		n--;
		return printX(n);
	} 
	else return 0;

}


char moveX () {

	char word;
	int aux = 0;
	scanf("%c", &word);
	
	if ( word != 'x' && word != '\n') {
		printf("%c", word);
		moveX();
	} else if (word == 'x' && word != '\n'){
		aux++;
		moveX();
	} 

	return printX(aux);
}




int main() {

	moveX();
	puts("\n");
}


