#include <stdio.h>
#include <stdlib.h>//rand()
#include <time.h>
int main(){
    srand(time(NULL));
    int number = rand() % 1001;
    printf("%d\n", number);
    return 0;
}