#include <stdio.h>
#include <stdbool.h>

//imprime no formato [a, b, c]
void vet_print(int vet[], int size){
    printf("[");
    if(size > 0)
        printf("%d", vet[0]);
    for(int i = 1; i < size; i++)
        printf(", %d", vet[i]);
    printf("]\n");
}

int main(){
    {
        int vet[10];
        for(int i = 0; i < 10; i++)
            vet[i] = i;
        for(int i = 0; i < 10; i++)
            printf("%d ", vet[i]);
        puts("");
    }
    {
        int vet[] = {4, 5, 3, 6, 5, 8, 9, 1, 2, 3};
        int size = sizeof(vet) / sizeof(int);
        int cont = 0;
        for(int i = 0; i < size - 1; i++)
            if(vet[i] > vet[i + 1])
                cont++;
        printf("cegos: %d\n", cont);
    }
    {
        int vet[] = {4, -5, 3, -6, 5, 8, -9, 1, -2, -3};
        //-5 -6 -9 -2 -3
        int size = sizeof(vet) / sizeof(int);
        printf("[ ");
        for(int i = 0; i < size; i++){
            if(vet[i] < 0){
                printf("%d.", vet[i]);
            }
        }
        printf("]\n");
    }
    {
        int vet[] = {4, -5, 3, -6, 5, 8, -9, 1, -2, -3};
        //
        int size = sizeof(vet) / sizeof(int);
        printf("[");
        for(int i = 0; i < size; i++){
            if(i != 0)
                printf(", ");
            printf("%d", vet[i]);
        }
        printf("]\n");
    }
    {
        int vet[] = {4, -5, 3, -6, 5, 8, -9, 1, -2, -3};
        int size = sizeof(vet) / sizeof(int);
        bool primeiro = true;
        printf("[");
        for(int i = 0; i < size; i++){
            if(vet[i] < 0){
                if(primeiro)
                    primeiro = false;
                else
                    printf(", ");
                printf("%d", vet[i]);
            }
        }
        printf("]\n");
    }

    {
        int vet[] = {4, -5, 3, -6, 5, 8, -9, 1, -2, -3};
        int size = sizeof(vet) / sizeof(int);
        vet_print(vet, size);
    }
    return 0;
}

/*
7
2 n
1 n
-3 n
5 n 
2 s
-4 s 
6 n
*/
