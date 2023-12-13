#include <stdio.h>
#include <stdlib.h>

/*

    Aprendendo alocação dinâmica de memória

*/


int main(void) {

    /*

        A função malloc retorna um ponteiro para a região de memória alocda
        caso a alocação não tenha sido bem sucedida, retorna um ponteiro NULL

    */

   int *x = malloc(sizeof(int)); //como retorna um ponteiro, precisa ser desse tipo

    if (x)
        printf("Alocado\n");
        //*x = 50;
    else
        printf("Não foi possível alocar\n");


}


























