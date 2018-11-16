#include <stdio.h>
#include <memory.h>

int main(){
    int vet[20];
    int size = sizeof(vet) / sizeof(int);
    for(int i = 0; i < size; i++)
        vet[i] = i;
    for(int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    puts("");

    int vaux[20];
    memcpy(vaux, vet, sizeof(vet));
    for(int i = 0; i < size; i++)
        printf("%d ", vaux[i]);

    vaux[0] += 1;
    int result = memcmp(vet, vaux, sizeof(vet));

    if(result == 0)
        puts("sao iguais");
    else if(result < 0)
        puts("vet eh menor");
    else
        puts("vet eh maior");
    return 0;
}