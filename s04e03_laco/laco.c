#include <stdio.h>

>>
7
5 34 12 43 9 9 35
<<

int main(){
    int n = 0; //n de pessoas
    scanf("%d", &n);
    float soma = 0;
    float valor = 0;
    for(int i = 0; i < n; i++){
        scanf("%f", &valor);
        soma += valor; 
    }
    float media = soma / n;
}