#include <stdio.h>
#include <stdlib.h>

//cria uma copia e coloca apenas os menores

int main(){
    int size = 10;
    int * vet = malloc(size * sizeof(int));
    for(int i = 0; i < 10; i++)
        vet[i] = i;
    {    
        int * vaux = malloc(2 * size * sizeof(int));
        for(int i = 0; i < size; i++)
            vaux[i] = vet[i];
        free(vet);
        vet = vaux;
        size = size * 2;
    }
    vet = realloc(vet, 10 * size);
    if(vet == NULL)
        puts("Nao deu!");
    else
        size = 2 * size;
    free(vet);
}