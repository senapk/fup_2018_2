#include <stdio.h>

float soma(float a, float b){
    float c = a + b;
    return c;
}

int main(){
    int x = 5;
    int y = 7;
//    float a = x;
//    float b = y;
    int z = soma(x, y);
    printf("%d\n", z);
    return 0;
}