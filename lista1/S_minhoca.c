#include <stdio.h>

int main(){

    int m,n, somaCol = 0, soma = 0;
    scanf("%d %d", &m,&n);
    int mat[m][n];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++n) {
            scanf("%d",&mat[i][j]);
        }
    }


      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++n) {
            somaCol += mat[j][i];
        }

        if (somaCol > soma) soma = somaCol;
        somaCol = 0;

    }
 

        printf("%d\n", soma);

    }


