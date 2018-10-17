#include <stdio.h>
//#include <ctype.h> isalpha isdigit toupper
#include <string.h>
#include <stdbool.h>

bool isalpha(char c){
    if(c >= 'a' && c <= 'z')
        return true;
    if(c >= 'A' && c <= 'A')
        return true;
    return false;
}

char toupper(char c){
    if(c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
}

void strcpy(char * dest, char * origem){
    /*     
    int i = 0;
    for(;origem[i] != '\0'; i++)
        dest[i] = origem[i];
    dest[i] = '\0';
    */
    while(*origem != '\0'){
        *dest = *origem;
        dest += 1;
        origem += 1;
    }
    *dest = '\0';
}

void strcat(char * dest, char * origem){
    int i = 0;
    while(dest[i] != '\0')
        i++;
    //opcao 1
    //strcpy(&dest[i], origem);
    for(int j = 0; origem[j] != '\0'; j++, i++)
        dest[i] = origem[j];
    dest[i] = '\0';
}

void strcatp(char * dest, char * origem){
    while(*dest != '\0')
        dest++;
    while(*origem != '\0'){
        *dest = *origem;
        dest += 1;
        origem += 1;
    }
    *dest = '\0';
}

int strlen(char * str){
    for(int i = 0;;i++)
        if(str[i] == '\0')
            return i;
}

int strlenp(char * str){
    int cont = 0;
    while(*str != '\0')
        cont++;
    return cont;
}

int strcmp(char * one, char * two){
    while(true){
        if((*one == '\0') && (*two != '\0'))
            return -1;
        if((*one != '\0') && (*two == '\0'))
            return 1;
        if((*one == '\0') && (*two == '\0'))
            return 0;
        if(*one != *two)
            return (*one < *two) ? -1 : 1;
        one += 1;
        two += 1;
    }
}


int main(){
    /* int vet[] = {1, 2, 3, 2, 6};
    sizeof(vet);//40 bytes
    int * p = &vet[0]; */

    //c
    const char * nome = "ovomaltine";
    sizeof(nome); //8
    
    char bebida[] = "ovomaltine";
    sizeof(bebida); //11

    char frase[100];
//    frase = "Hoje sera";
    strcpy(frase, "Hoje sera");

    strcat(frase, " um dia lindo");
    char * esperanca = "Amanha sera melhor ainda";
    
    if(strcmp(frase, esperanca) > 0)
        printf("%s", frase);
    else
        printf("%s", esperanca);

    printf("\n%i\n", (int)strlen(frase));
}