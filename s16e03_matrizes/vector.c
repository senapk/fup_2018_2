#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int * data;
    int capacity;
    int size;
} vector;

vector * vec_create(int capacity){
    vector * vec = malloc(sizeof(vector));
    vec->data = malloc(capacity * sizeof(int));
    vec->capacity = capacity;
    vec->size = 0;
    return vec;
}

void vec_destroy(vector * vec){
    free(vec->data);
    free(vec);
}

bool vec_push_back(vector * vec, int value){
    if(vec->size == vec->capacity){
        int * temp = realloc(vec->data, 2 * vec->size * sizeof(int));
        if(temp == NULL){
            puts("erro erro erro erro");
            return false;
        }
        vec->data = temp;
        vec->capacity = 2 * vec->capacity;
    }
    vec->data[vec->size] = value;
    vec->size += 1;
    return true;
}

bool vec_pop_back(vector * vec){
    if(vec->size > 0){
        vec->size -= 1;
        return true;
    }
    return false;
}

int main(){
    srand(time(NULL));

    int size = rand() % 50;
    vector * vec = vec_create(1);
    for(int i = 0; i < size; i++){
        vec_push_back(vec, rand() % 10);
    }

    for(int i = 0 ; i < vec->size; i++)
        printf("%d ", vec->data[i]);

    printf("\ncap %d\n", vec->capacity);


}