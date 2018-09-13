#include <stdio.h>
#include <stdbool.h>

int main(){
    int lim_sup = 1000;
    int lim_inf = 0;
    int qtd_chutes = 0;
    int opcao = 0;

    puts("Pense num numero no intervalo [0, 1000]");
    while(true){
        qtd_chutes += 1;
        int chute = (lim_sup + lim_inf) / 2;
        printf("Chuto %d. (1)acertei? (2)Eh menor? (3) Eh maior: ", chute);
        scanf("%d", &opcao);
        if(opcao == 1)
            break;
        else if(opcao == 2)
            lim_sup = chute - 1;
        else
            lim_inf = chute + 1;
    }

    printf("acertou em %d chutes", qtd_chutes);
    return 0;
}