#include <stdio.h>
#include <stdbool.h>

int main(){
    int lim_sup = 100;
    int lim_inf = 0;
    int qtd_chutes = 0;
    int opcao = 0;

    printf("Pense num numero no intervalo aberto ]0, 100[ e digite Enter para continuar");
    getchar();
    while(true){
        if(lim_inf + 1 == lim_sup){
            printf("Não existem numeros entre %d e %d\n", lim_inf, lim_sup);
            break;
        }
        if(lim_inf + 2 == lim_sup){
            printf("Seu número é %d\n", lim_inf + 1);
            printf("Acertei em %d chutes\n", qtd_chutes);
            break;
        }
        qtd_chutes += 1;
        int chute = (lim_sup + lim_inf) / 2;
        printf("%d: Chuto %2d entre ]%3d, %3d[.", qtd_chutes, chute, lim_inf, lim_sup);
        printf("  (1)Acertei? Seu número eh (2)menor ou (3)maior?: ");
        scanf("%d", &opcao);
        if(opcao == 1)
            break;
        else if(opcao == 2)
            lim_sup = chute;
        else
            lim_inf = chute;
    }
    return 0;
}