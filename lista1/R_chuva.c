#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    int mat1[n][n];
    int mat2[n][n];

    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            scanf("%d", &mat1[i][j]);
        }
    }

    
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            scanf("%d", &mat2[i][j]);
        }
    }

    
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            printf("%d ", mat1[i][j]+mat2[i][j]);
        }
        printf("\n");
    }




}