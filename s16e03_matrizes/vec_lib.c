#include "vector.h"

int main(){
    Vet* v = vet_create(int);
    vet_add(v, 5, int);
    vet_add(v, 8, int);
    vet_add(v, 6, int);
    for(int i = 0; i < v->size; i++)
        printf("%d ", vet_data(v, int)[i]);
    printf("\n");
    int a;
    vet_destroy(v);
}