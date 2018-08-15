#include <stdio.h>
#include <stdlib.h>

int i = 0; //global

void mostra(int a){ //funcao
    printf("%d\n", a);
    printf("%d\n", i); //global
}

void soma_e_mostra(int i){
    i = i + 1; //sombreia a variavel i global
    printf("%d\n", i);
}

int main () {
    int i = 5;
    int a = 3;
    //int i = 4; //erro, redefinição de i
    printf("%d %d\n", i, a); //5 3
    {
        //novo escopo
        int i = 7; //sombreamento do i da linha 17
        int b = 2;
        printf("%d %d %d\n", i, a, b);//7 3 2
    }
    //printf("%d %d %d\n", i, a, b); //erro, b nao existe nesse escopo
    printf("%d %d\n", i, a);//5 9

    return 0;
}