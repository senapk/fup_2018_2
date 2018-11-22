#include <stdio.h>

int main(){
    int vet[] = {0, 4, 0, 3, 0, 0, 10};
    int mat[3][4] = {{0, 0, 0, 0},
                    {1, 0, 2, 0}, 
                    {0, 2, 0, 0}};

    int size = sizeof(vet) / sizeof(int);
    int nl = 3;
    int nc = 4;

    int dano[size];
    
    for(int i = 0; i < size; i++){
        int val = vet[i];
        for(int c = i - (val - 1); c <= (i + (val - 1)); ++c){
            for(int l = )
            if(c >= 0 && c < size)
                dano[c] += 1;
        }
    }
    printf("[ ");
    for(int i = 0; i < size; i++)
    printf("%d ", dano[i]);
    printf("]");
}