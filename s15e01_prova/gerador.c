#include <stdio.h>
#include <time.h>//time
#include <stdlib.h>//rand e sra
#include <stdbool.h>
#include <string.h>

//sortear uma vogal
char rand_vowel(){
    char * list = "aeiou";
    int len = strlen(list);
    return list[rand() % len];
}

//sortear uma consoante
char rand_cons(){
    char * list = "bcdfghjklmnpqrstvwxyz";
    int len = strlen(list);   
    return list[rand() % len]; 
}

//criar um nome aleatório ente 3 e 7 caracteres
void rand_name(char nome[8]){
    bool actual_is_vowel = rand() % 2; //se comeca com vogal
    for(int i = 0; i < 8; i++){
        nome[i] = actual_is_vowel ? rand_vowel() : rand_cons();
        //sempre troca, a não ser que esteja numa vogal e com 20% de chance teremos outra vogal
        if(!(actual_is_vowel && (rand() % 100 < 20)))
            actual_is_vowel = !actual_is_vowel; //inverte
    }
    nome[0] = nome[0] - ('a' - 'A'); //tornando a primeira maiúscula
    
    //colocando o \0 entre o 3 e o 7 para cortar o nome
    //(3-7) = (0-4) + 3
    nome[(rand() % 5) + 3] = '\0';
}

int main(){
    srand(time(NULL));
    char fullname[30] = "\0";
    char name[8];
    //sorteia quantos nomes ele terá, de 2 até 4
    int qtd_names = (rand() % 3) + 2; //(0 - 2) + 2 == (2 - 4) names
    for(int i = 0; i < qtd_names; i++){
        rand_name(name); //gera um nome e vai concatenando
        strcat(fullname, name);
        strcat(fullname, " ");
    }
    int len = strlen(fullname);
    fullname[len] = '\0'; //retirar o ultimo espaco;
    puts(fullname);
}