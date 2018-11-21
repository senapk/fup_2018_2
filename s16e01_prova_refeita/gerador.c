#include <string.h>//strlen, strcat, strcmp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char sortear_vogal(){
    char * vogais = "aeiou";
    return vogais[rand() % 5]; 
}

char sortear_cons(){
    char * vogais = "bcdfghjklmnpqrstvwxyz";
    return vogais[rand() % 21]; 
}

void preencher_nome(char nome[]){
    int len = (rand() % 5) + 3; //3 - 7 == (0 - 4) + 3
    //char nome[len + 1];
    nome[len] = '\0';
    bool eh_vogal = rand() % 2;
    for(int i = 0; i < len; i++){
        if(!eh_vogal && (rand() % 100 < 20))
            eh_vogal = true;
        nome[i] = eh_vogal ? sortear_vogal() : sortear_cons();
        eh_vogal = !eh_vogal;
    }
    nome[0] = nome[0] - ('a' - 'A');
}


int rand_int(int min, int max){
    return (rand() % max - min + 1) + min;
}

void gerar_nome_completo(char nome_comp[]){
    int qtd = rand() % 3 + 2;
    for(int i = 0; i < qtd; i++){
        char nome[10];
        preencher_nome(nome);
        strcat(nome_comp, nome);
        strcat(nome_comp, " ");
    }
    nome_comp[strlen(nome_comp) - 1] = '\0';
}

int main(){
    srand(time(NULL));
    char nome[100];
    gerar_nome_completo(nome);
    printf("%s\n", nome);
}