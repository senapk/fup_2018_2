#include <stdio.h>

/*
5
9
5
4
3
1
*/

int main(){
    int size = 0;
    int soma = 0;
    scanf("%d", &size);
    int vetor[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    float media = (float)soma/size;
    printf("media: %f\n", media);
    int cont = 0;
    for(int i = 0; i < size; i++){
        if(vetor[i] < media)
            cont++;
    }
    printf("menores %d\n", cont);
    return 0;
}