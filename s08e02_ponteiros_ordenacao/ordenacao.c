#include <stdio.h>  //printf, sizeof
#include <stdlib.h> //qsort

int compara_int(const void * a, const void * b){
    return *(int *) a - *(int *) b;
}

int main(){
    int vet[] = {4, 5, 1, 2, 3, 6, 2, 8, 9, 10, 14, 11, -1, -2};
    int size = sizeof(vet) / sizeof(int);

    //qsort(begin, size, sizeof(type), funcao_comparacao)
    qsort(vet, size, sizeof(int), compara_int);

    printf("[%d", vet[0]);
    for(int i = 1; i < size; i++)
        printf(", %d", vet[i]);
    printf("]\n");   

    return 0;
}
