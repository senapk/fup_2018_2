#include <stdio.h>
#include <stdbool.h>

void vet_show(int vet[], int size){
    printf("[ ");
    for(int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int find_ind_menor(int vet[], int inicio, int size){
    int imenor = inicio;
    for(int i = inicio + 1; i < size; i++){
        if(vet[i] < vet[imenor])
            imenor = i;
    }
    return imenor;
}

void selection_sort(int vet[], int size){
    for(int i = 0 ; i < size; i++){
        int imenor = find_ind_menor(vet, i, size);
        swap(vet + i, vet + imenor);
        vet_show(vet, size);
    }
}

void append(int vet[], int *size, int value){
    vet[*size] = value;
    *size += 1;
}

bool exist(int vet[], int size, int value){
    for(int i = 0; i < size; i++)
        if(vet[i] == value)
            return true;
    return false;
}

int contar(int vet[], int size, int value){
    int cont = 0;
    for(int i = 0; i < size; i++)
        if(vet[i] == value)
            cont++;
    return cont;
}

int main(){
    int vet[] = {1, -3, 2, 3, 5, 7, -2, -3, -4, 6, 7, 9, -3};
    int size = sizeof(vet)/sizeof(int);
    selection_sort(vet, size);
    vet_show(vet, size);

    int exemp[size];
    int exemp_size = 0;

    for(int i = 0; i < size; i++)
        if(!exist(vet, i, vet[i]))
            append(exemp, &exemp_size, vet[i]);

    vet_show(exemp, exemp_size);

    printf("[ ");
    for(int i = 0; i < size; i++){
        if(contar(vet, size, vet[i]) == 1)
            printf("%d ", vet[i]);
    }
    printf("]\n");


    int max_vezes = 0;
    for(int i = 0; i < size; i++){
        int vezes = contar(vet, size, vet[i]);
        if(vezes > max_vezes)
            max_vezes = vezes;
    }

    for(int i = 0; i < size; i++){
        int vezes = contar(vet, size, vet[i]);
        if(vezes == max_vezes)
            printf("%d ", vet[i]);
    }

    printf("\n");

    int ganh[size];
    int ganh_size = 0;

    int max = 0;

    for(int i = 0; i < size; i++){
        int qtd = contar(vet, size, vet[i]);
        if(qtd > max){
            max = qtd;
            ganh_size = 0;
            append(ganh, &ganh_size, vet[i]);
        }else if(qtd == max){
            if(!exist(ganh, ganh_size, vet[i]))
                append(ganh, &ganh_size, vet[i]);
        }
    }
    vet_show(ganh, ganh_size);
}

