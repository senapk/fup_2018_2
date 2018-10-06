#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef enum {FALSE, TRUE} BOOL;
typedef enum {Ouros, Espadas, Copas, Paus} Naipe;
const char * naipe_nomes[] = {"Ouros", "Espadas", "Copas", "Paus"};

//esses valores representam os hexadecimais Unicode que imprimem os simbolos
const char * naipe_nomes[] = {"\xe2\x99\xa6", "\xe2\x99\xa0", "\xe2\x99\xa5", "\xe2\x99\xa3"};

#define SWAP(a, b, tipo) do{tipo SWAP = a;a = b;b = SWAP;}while(0)

typedef struct{
    int valor;
    Naipe naipe;
} Carta;

void carta_show(Carta carta){
    if(carta.valor == 1)
        printf("As");
    else if(carta.valor <= 10)
        printf("%d", carta.valor);
    else if(carta.valor == 11)
        printf("J");
    else if(carta.valor == 12)
        printf("Q");
    else
        printf("K");
    printf(" de ");
    if(carta.naipe == Ouros)
        printf("Ouros");
    else if(carta.naipe == Copas)
        printf("Copas");
    else if(carta.naipe == Espadas)
        printf("Espadas");
    else
        printf("Paus");
}


void embaralhar(Carta baralho[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        SWAP(baralho[i], baralho[pos], Carta);
    }
}

void carta_show(Carta carta){
    char valores[] = " A234567890JQK";
    printf("[");
    if(carta.valor == 10)
        printf("10");
    else
        printf(" %c", valores[carta.valor]);
    printf("%s]", naipe_nomes[carta.naipe]);
}

void baralho_iniciar(Carta baralho[52]){
    int cont = 0;
    for(int naipe = 0; naipe < 4; naipe++)
        for(int valor = 1; valor < 14; valor++, cont++)
            baralho[cont] = (Carta){valor, naipe};
}

void baralho_show(Carta baralho[], int size){
    printf("Mao:");
    for(int i = 0; i < size; i++){
        if(i % 13 == 0)
            printf("\n");
        carta_show(baralho[i]);
    }
    puts("");
}

void mao_show(Carta mao[], int size){
    printf("Mao\n");

    for(int i = 0; i < size; i++)
        printf("  %d  ", i);
    puts("");
    for(int i = 0; i < size; i++)
        carta_show(mao[i]);
    puts("");
}

void transferir_carta(Carta destino[], int *destino_size, 
                  Carta origem[], int *origem_size){
    destino[*destino_size] = origem[*origem_size - 1];
    *origem_size -= 1;
    *destino_size += 1;
}

#define MAXSIZE 52

void ordenar(Carta mao[], int size){
    for(int i = 0; i < size - 1; i++){
        int imenor = i;
        for(int j = i + 1; j < size; j++){
            if(mao[j].valor < mao[imenor].valor)
                imenor = j;
        }
        SWAP(mao[i], mao[imenor], Carta);
    }
}

bool ganhou(Carta mao[], int size){
    ordenar(mao, size);
    for(int i = 0; i < 9; i += 3){
        if(!((mao[i].valor == mao[i + 1].valor) && 
             (mao[i].valor == mao[i + 2].valor)))
            return false;
    }
    return true;
}

Carta remover(Carta mao[], int *size, int indice){
    Carta carta = mao[indice];
    for(int i = indice; i < *size - 1; i++)
        mao[i] = mao[i + 1];
    *size -= 1;
    return carta;
}

int main(){
    srand(time(NULL));
    Carta baralho[MAXSIZE];
    int baralho_size = sizeof(baralho) / sizeof(Carta);

    Carta mao[MAXSIZE];
    int mao_size = 0;

    baralho_iniciar(baralho);
    embaralhar(baralho, baralho_size);
    baralho_show(baralho, baralho_size);
    for(int i = 0; i < 9; i++)
        transferir_carta(mao, &mao_size, baralho, &baralho_size);
    baralho_show(baralho, baralho_size);
    mao_show(mao, mao_size);
    ordenar(mao, mao_size);
    mao_show(mao, mao_size);
    
    while(!ganhou(mao, mao_size)){
        int indice;
        printf("Qual carta voce vai descartar 0-8? Digire S para ordenar");
        scanf("%d", &indice);
        remover(mao, &mao_size, indice);
        transferir_carta(mao, &mao_size, baralho, &baralho_size);
        ordenar(mao, mao_size);
        mao_show(mao, mao_size);
    }

    return 0;
}