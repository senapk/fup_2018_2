#include <stdio.h>
#include <stdlib.h>

void rodarvet(int vet[], int size){
    int primeiro = vet[0];
    for(int i = 1; i < size; i++)
        vet[i - 1] = vet[i];
    vet[size-1] = primeiro;
}

int main(int argc, char * argv[]){
    if(argc < 3){
        printf("use ./remocao size escolhido\n");
        return 1;
    }
    int size = atoi(argv[1]);
    int escolhido = atoi(argv[2]);

    int vet[size];

    for(int i = 0; i < size; i++)
        vet[i] = i + 1;

    while(vet[0] != escolhido)
        rodarvet(vet, size);

    while(size > 1){
        rodarvet(vet, size);
        
        //printf("%d mata %d\n", vet[size - 1], vet[0]);
        rodarvet(vet, size); //matar
        size -= 1;                 //matar
    }

    printf("%d\n", vet[0]);
    
    return 0;
}
