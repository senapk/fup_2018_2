#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {NONE, PEAO, REI, TORRE, RAINHA, BISPO, CAVALO} Tipo;
const char * tipo_nomes[] = {"--", "PE", "RE", "TO", "RA", "BI", "CA"};
typedef enum {BRANCO, PRETO} Cor;
const char * cor_nome = "BP";

typedef struct{
    Tipo tipo;
    Cor cor;
} Peca; //8 bytes

Peca tab[8][8];

void peca_show(Peca peca){
    char cor = cor_nome[peca.cor];
    if(peca.tipo == NONE)
        cor = '-';
    printf("%s.%c", tipo_nomes[peca.tipo], cor);
}

void tabuleiro_arrumar(Peca tab[][8]){
    for(int l = 0; l < 8; l++)
        for(int c = 0; c < 8; c++)
            tab[l][c] = (Peca){NONE, BRANCO};
/*     
    Peca * vet = &tab[0][0];
    for(int i = 0; i < 64; i++)
        vet[i] = (Peca){NONE, BRANCO};
*/    
    for(int i = 0; i < 8; i++){
        tab[1][i] = (Peca){PEAO, PRETO};
        tab[6][i] = (Peca){PEAO, BRANCO};
    }

    Tipo vpeca[] = {TORRE, CAVALO, BISPO, REI, RAINHA, BISPO, CAVALO, TORRE};
    for(int i = 0; i < 8; i++){
        tab[0][i] = (Peca){vpeca[i], PRETO};
        tab[7][i] = (Peca){vpeca[7 - i], BRANCO};
    }
}

void tabuleiro_show(Peca tab[8][8]){
    for(int l = 0; l < 8; l++){
        printf("{ ");
        for(int c = 0; c < 8; c++){
            peca_show(tab[l][c]);
            printf(" ");
        }
        printf("}\n");
    }
}

int main(){
    printf("%ld\n", sizeof(Tipo));
    printf("%ld\n", sizeof(Peca));
    
    Peca tab[8][8];
    tabuleiro_arrumar(tab);
    tabuleiro_show(tab);
    
    return 0;
}