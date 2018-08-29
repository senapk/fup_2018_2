#include <stdio.h>
#include <stdbool.h>

int main(){
    int d1 = 0; //dedos jogador 1
    int d2 = 0; //dedos jogador 2
    puts("Mostrem os dedos _d1 _d2");
    scanf("%d %d", &d1, &d2);
    getchar();//se livrar do \n
    int soma = d1 + d2;
    char letra = (soma - 1) % 26 + 'a';
    printf("A soma eh %d\n", soma);
    printf("A letra eh %c\n", letra);    
    char palavra[50];
    while(true){
        puts("Jogador 1");
        fgets(palavra, sizeof(palavra), stdin);
        //scanf("%s", palavra);
        if(palavra[0] != letra){
            puts("Jogador 2 ganhou");
            return 0;
        }
        puts("Jogador 2");
        fgets(palavra, sizeof(palavra), stdin);
        if(palavra[0] != letra){
            puts("Jogador 1 ganhou");
            return 0;
        }
    }
    return 0;
}