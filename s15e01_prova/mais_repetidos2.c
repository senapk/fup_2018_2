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
bool exist(int vet[], int size, int value){
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

    int ganh[vet_size];
    int ganh_size = 0;
    int max = 0;

/*
    para cada elemento 'elem' no vetor 'vet'
        'cont' = quantas vezes 'elem' aparece em 'vet'
            se 'cont' for igual ao maximo
                se elem nao esta no vetor de ganhadores
                    adicione elem no vetor de ganhadores
            senao se 'cont' > max
                maximo recebo cont
                esvazie o vetor de ganhadores
                insira elem no vetor de ganhadores
*/

    for(int i = 0; i < vet_size; i++){
        int qtd = count(vet, vet_size, vet[i]);
        if(qtd == max){
            if(!exist(ganh, ganh_size, vet[i]))
                append(ganh, &ganh_size, vet[i]);
        }if(qtd > max){
            max = qtd;
            ganh_size = 0;
            append(ganh, &ganh_size, vet[i]);
        }
    }
    //ordenando o vetor de ganhadores
    qsort(ganh, sizeof(int), ganh_size, compara_int);
    printf("%d vezes\n", max);
    for(int i = 0; i < ganh_size; i++)
        printf("%d ", ganh[i]);
    puts("fim");
}
