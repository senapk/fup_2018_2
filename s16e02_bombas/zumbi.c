#include <stdio.h>


int main(){
    FILE * fmat = fopen("input.txt", "r");
    if(fmat == NULL){
        puts("erro no arquivo");
        return 1;
    }
    int nl = 0, nc = 0;
    fscanf(fmat, "%d %d", &nl, &nc);
    
    int mat[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            fscanf(fmat, "%d", &mat[l][c]);
    }
/* 
    int * vet = &mat[0][0];
    for(int i = 0; i < nl * nc;  i++)
        fscanf(fmat, "%d", &vet[i]); */
    
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            printf("%d ", mat[l][c]);
        }
        puts("");
    }
}

