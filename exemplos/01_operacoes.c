#include <stdio.h>
#include <stdbool.h> //c99


int main(){
    int a = 6;
    int b = 3;
    int c = a + b - a * b / a;

    float d = b/a; // 0.0 divisao inteira -> resultado inteiro
    float e = (float) b / a; //0.5
    float f = b / 2.0;

    b += 5; //b = b + 5

    int g = 5 % 3; //modulo

    bool passei = false || true || false; //true se pelo menos 1 for true
    bool selaskey = false && false && false && true; //false se pelo menos 1 for false

    passei = !passei; //operador de negacao

    return 0;
}