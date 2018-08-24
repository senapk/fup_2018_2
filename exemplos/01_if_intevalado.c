#include <stdio.h>

int main(){
    int x;
    puts("Digite sua idade");

    scanf("%d", &x);
    if(x < 0)
        puts("Voce ainda esta na barriga");
    else if(x < 13)
        puts("Crianca");
    else if(x < 18)
        puts("Menor infrator");
    else if(x < 65)
        puts("Adulto");
    else if(x < 100)
        puts("Vei");
    else
        puts("Heroi");
    return 0;
}