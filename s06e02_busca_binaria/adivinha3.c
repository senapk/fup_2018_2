#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //rand srand
#include <time.h> //time

/*
inf e sup

1 e 3
5 e 9
10 e 20

rand() % 11 - 0 a 10

rand() % (sup - inf + 1) + inf


40 e 100
rand() % 61 = 0 - 60
rand() % (sup - inf + 1) 0 - 60

*/

[1, 0, 0, 0, 0, 0, 0, 0, 1, 2]

int rand_fechado(int menor, int maior){
    return rand() % (maior - menor + 1) + menor;
}
]4, 10[
[5, 9]

int rand_aberto(int menor, int maior){
    //return rand_fechado(menor + 1, maior -1);
    return rand() % (maior - menor - 1) + menor + 1;
}




int main(){
    srand(time(NULL));
    int lim_sup = 1000;
    int lim_inf = 0;
    int qtd_chutes = 0;
    int numero = rand() % 1001;

    printf("Bob escolheu %d, mas Alice nao sabe\n", numero);
    while(true){
        qtd_chutes += 1;
        int chute = randmm(lim_inf, lim_sup);
        printf("%2d: Alice: [%d, %d] Chuto %d", qtd_chutes, lim_inf, lim_sup, chute);
        if(numero == chute){
            printf("  Bob diz acertou\n");
            break;
        }else if(numero < chute){
            printf("  Bob diz eh menor");
            lim_sup = chute - 1;
        }else{
            printf("  Bob diz eh maior");
            lim_inf = chute + 1;
        }
        getchar();
    }

    printf("acertou em %d chutes", qtd_chutes);
    return 0;
}