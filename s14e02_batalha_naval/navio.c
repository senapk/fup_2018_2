#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/*
# nao sei
. nao tem nada
o pedaco de navio

 abcdefghi
a   o
b   .
c
d 3
e
f
g

lc >> bd

abcdefghijklmnopqrstuvwxyz
##########################
  333    1   22 4444

abcdefghij
##########
>> a
abcdefghij
.#########
>> d 
.##o######
*/

void inserir_barco(int * navios, int LARG, int nsize){
    while(true){
        int pos = rand() % (LARG - nsize + 1);
        bool nao_cabe = false;
        for(int i = pos; i < (pos + nsize); i++){
            if(navios[i] != 0){
                nao_cabe = true;
                break;
            }
        }
        if(nao_cabe)
            continue;
        for(int i = pos; i < pos + nsize; i++)
            navios[i] = nsize;
        return;
    }
}

void init_game(char * mar, int * navios, int LARG){
    mar[LARG + 1] = '\0';
    for(int i = 0; i < LARG; i++)
        mar[i] = '#';
    for(int i = 0; i < LARG; i++)
        navios[i] = 0;
    for(int i = 1; i <= 4; i++)
        inserir_barco(navios, LARG, i);
}

void mar_mostrar(char mar[], int LARG){
    for(char c = 'a'; c < ('a' + LARG); c++)
        printf("%c", c);
    puts("");
    for(int i = 0; i < LARG; i++)
        printf("%c", mar[i]);
    puts("");
}

void mar_alterar(char * mar, int * navios, int LARG, int pos){
    if(navios[pos] != 0){
        mar[pos] = navios[pos] + '0';
        navios[pos] = 0;
    }else
        mar[pos] = '.';
}

int pegar_input(char * mar, int LARG){
    while(true){
        char opcao;
        printf(">> ");
        scanf(" %c", &opcao);

        int pos = opcao - 'a';
        if(pos < 0 || pos >= LARG){
            puts("posicao invalida");
            continue;
        }
        if(mar[pos] != '#'){
            puts("posicao ja foi escolhida");
            continue;
        }
        return pos;
    }
}

bool ainda_existem_navios(int * navios, int LARG){
    for(int i = 0; i < LARG; i++)
        if(navios[i] != 0)
            return true;
    return false;
}

int main(){
    srand(time(NULL));
    int LARG = 26;
    char mar[LARG][LARG];
    int navios[LARG];
    init_game(mar, navios, LARG);
    
    while(ainda_existem_navios(navios, LARG)){
        mar_mostrar(mar, LARG);
        int pos = pegar_input(mar, LARG);
        mar_alterar(mar, navios, LARG, pos);
    };
    mar_mostrar(mar, LARG);

    return 0;
}