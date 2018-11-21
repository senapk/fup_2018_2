#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//conta quantas vezes o valor aparece no vetor
int count(int vet[], int size, int value){
    int cont = 0;
    for(int i = 0; i < size; i++)
        if(vet[i] == value)
            cont++;
    return cont;
}

//adiciona value no fim de vet
void append(int vet[], int * size, int value){
    vet[*size] = value;
    *size += 1;
}

//retorna se o valor existe no vetor
bool exists(int vet[], int size, int value){
    for(int i = 0; i < size; i++)
        if(vet[i] == value)
            return true;
    return false;
}

int compara_int(const void * a, const void * b){
    return *(int*)a - *(int *)b;
}

int main(){
    int vet[] = {1, 3, 4, -1, 2, 2, 4, -3, 2, -1, 1, -3, -2, 4, -1, 1};
    int vet_size = sizeof(vet) / sizeof(int);

    int exem[vet_size];
    int exem_size = 0;

    //preenchendo o vetor de exemplares
    for(int i = 0; i < vet_size; i++)
        if(!exists(exem, exem_size, vet[i]))
            append(exem, &exem_size, vet[i]);

    for(int i = 0; i < exem_size; i++)
        printf("%d ", exem[i]);
    puts("");

    //criando um vetor para contar quantas vezes esses elementos aparecem
    int cont[exem_size];
    for(int i = 0; i < exem_size; i++)
        cont[i] = count(vet, vet_size, exem[i]);

    //cont agora tem as quantidade de cada elemento, vamos procurar o número que se repete mais
    int max = cont[0];
    for(int i = 1; i < exem_size; i++)
        if(cont[i] > max)
            max = cont[i];
    
    //agora criar um novo vetor com os ganhadores
    int ganh[exem_size];
    int ganh_size = 0;
    for(int i = 0; i < exem_size; i++)
        if(cont[i] == max)
            append(ganh, &ganh_size, exem[i]);
    
    //ordenando o vetor de ganhadores
    qsort(ganh, sizeof(int), ganh_size, compara_int);
    printf("%d vezes\n", max);
    for(int i = 0; i < ganh_size; i++)
        printf("%d ", ganh[i]);
    puts("fim");
}