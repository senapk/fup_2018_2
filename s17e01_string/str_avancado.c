#include <string.h> //strlen, strcat, strcpy, strcmp
#include <stdio.h>
#include <stdlib.h> //strtol
//strsep
//strtok
//strtok_r
//strtol


char * preenche_palavra(char * texto, char * palavra[]){
    int ind = 0;
    while((*texto != ' ') && (*texto != '\0')){
        palavra[ind] = *texto;
        ind++;
        texto++;
    }
    palavra[ind] = '\0';
    return texto + 1;
}

int tirando_tokens1(){
    char frase[] = "comi eu um vatapa xtragado";
    char palavra[50];
    
    char *ptr = frase;        
    while(1){
        ptr = preenche_palavra(ptr, palavra);
        puts(palavra);
    }
    return 0;
}
int tirando_tokens2(){
    char frase[] = "comi eu um vatapa xtragado";

    char *token = frase;        
    char *line = frase;
    while(1){
        token = strsep(&line, " "); 
        if(token == NULL)
            break;
        printf("%s %s ", token, token);
    }
    return 0;
}

void converter(){
    char palavra[] = "10010111";
    int valor = strtol(palavra, NULL, 16);
    printf("%d\n", valor); //183
}
int main(){
    tirando_tokens();
    return 0;
}


/* int main(){
    char frase[50];
    fgets(frase, 50, stdin);
    frase[strlen(frase) - 1] = '\0';
    int size = strlen(frase);
    printf("%s %d", frase, size);
    return 0;
} */