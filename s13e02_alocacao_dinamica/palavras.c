#include <string.h>
#include <stdio.h>

int is_blank(char c){
    return (c == ' ') || (c == '\t') || (c == '\n');
}

int main(){
    char * frase = "o rato roeu \n \ta  roupa do rei de roma";
    //char frase[100];
    //fgets(frase, sizeof(frase), stdin);
    int size = strlen(frase);
    for(int i = 0; i < size; i++)
        if(!is_blank(frase[i])){
            if(i != 0 && is_blank(frase[i - 1]))
                printf("\n");
            printf("%c", frase[i]);
        }
}