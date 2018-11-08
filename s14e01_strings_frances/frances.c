#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool existe(int size, int pos){
    return(pos >= size || pos < 0);
}

bool eh_vogal(char c){
    char * vogais = "AEIOUaeiou";
    for(int i = 0; i < 10; i++)
        if(vogais[i] == c)
            return true;
    return false;
}

//remove espacos antes e depois
void trim(char * in, char * out){
    int size = strlen(in);
    int comeco = 0;
    while(in[comeco] == ' ')
        comeco++;
    int fim = size - 1;
    while(in[fim] == ' ')
        fim--;
    int j = 0;
    for(int i = comeco; i <= fim; i++, j++)
        out[j] = in[i];
    out[j] = '\0';
}

void juntar(char * entrada, char * saida){
    saida[0] = entrada[0];
    int j = 1;
    int size = strlen(entrada);

    for(int i = 1; i < size; i++){
        if(eh_vogal(entrada[i]) != eh_vogal(entrada[i - 1])){
            saida[j] = entrada[i];
            j++;
        }
        saida[j] = '\0';
    }
}

int main(){
    int MAX = 101;
    char entrada[MAX];
    char saida[MAX];
    fgets(entrada, MAX, stdin);
    juntar(entrada, saida);
    printf(saida);
}

