#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //rand srand
#include <time.h> //time

int rand_fechado(int menor, int maior){
    return rand() % (maior - menor + 1) + menor;
}

int rand_aberto(int menor, int maior){
    //return rand_fechado(menor + 1, maior -1);
    return rand() % (maior - menor - 1) + menor + 1;
}

int main(){
    srand(time(NULL));
    int lim_sup = 100;
    int lim_inf = 0;
    int qtd_chutes = 0;
    int numero = rand() % lim_sup + 1;

    printf("Bob escolheu %d, mas Alice nao sabe\n", numero);
    while(true){
        qtd_chutes += 1;
        //int chute = rand_aberto(lim_inf, lim_sup);
        int chute = (lim_inf + lim_sup) / 2;
        printf("%2d: ]%4d, %4d[ : Alice chuta : %d", qtd_chutes, lim_inf, lim_sup, chute);
        if(numero == chute){
            printf("  Bob diz acertou\n");
            break;
        }else if(numero < chute){
            printf("  Bob diz eh menor");
            lim_sup = chute;
        }else{
            printf("  Bob diz eh maior");
            lim_inf = chute;
        }
        getchar();
    }

    printf("Alice acertou em %d chutes", qtd_chutes);
    return 0;
}