#pragma once

#if 0
#include <stdio.h>
#include "vector.h"

typedef struct{
    int x, y;
}XY;

int main(){
    {
        Vet* v = vet_create(int);
        vet_add(v, 5, int);
        vet_add(v, 8, int);
        vet_add(v, 6, int);
        for(int i = 0; i < v->size; i++)
            printf("%d ", vet_data(v, int)[i]);
        printf("\n");
        vet_destroy(v);
    }
    {
        Vet* v = vet_create(char*);
        vet_add(v, "chiclete", char*);
        vet_add(v, "faz", char*);
        vet_add(v, "sucesso", char*);
        for(int i = 0; i < v->size; i++)
            printf("%s ", vet_at(v, i, char*));
        printf("\n");
        vet_destroy(v);
    }
    {
        Vet* v = vet_create(XY);
        vet_add(v, ((XY){4, 5}), XY);
        vet_add(v, ((XY){3, 6}), XY);
        vet_add(v, ((XY){6, 1}), XY);
        for(int i = 0; i < v->size; i++){
            XY * data = vet_data(v, XY);
            printf("(%d:%d) ", data[i].x, data[i].y);
        }
        printf("\n");
        vet_destroy(v);
    }
    
    return 0;
}


#endif



#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct{
    void * data;
    size_t capacity;
    size_t size;
    size_t sizeof_data;
}Vet;

//metodo para new, add, rm, data

Vet * __vet_create(int capacity, size_t sizeof_data){
    Vet * vet = (Vet *) malloc(sizeof(Vet));
    vet->data = calloc(capacity, sizeof_data);
    vet->sizeof_data = sizeof_data;
    vet->capacity = capacity;
    vet->size = 0;
    return vet;
}

void __vet_add(Vet * vet, void * value){
    if(vet->size == vet->capacity){
        vet->data = realloc(vet->data, 2 * vet->capacity);
        vet->capacity *= 2;
    }
    memcpy(vet->data + vet->sizeof_data * vet->size, value, vet->sizeof_data);
    vet->size += 1;
}

/* void __vet_rm(Vet * vet, int ind){
    if(ind < 0) || (int >= vet->size){
        printf("fail: indice invalido\n");
        return;
    }
    for(
    

}
 */

#define vet_create(type) (__vet_create(100, sizeof(type)))
#define vet_destroy(v) do{free(v->data); free(v);}while(0)
#define vet_add(v, value, type) do{type vet_add = value; __vet_add(v, &vet_add);}while(0)
#define vet_data(v, type) ((type*) v->data)
#define vet_at(v, ind, type) ((type*) v->data)[ind]
