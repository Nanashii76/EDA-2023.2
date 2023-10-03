#include <stdio.h>


int function (int n) {

	if (n >= 101) return n-10;

	else return function(function(n+11));


}




int main(){

	int n;
	
	scanf("%d", &n);

	while (n != 0) {
	
		printf("f91(%d) = %d\n", n, function(n));
	
		scanf("%d", &n);

	}

}
