#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // const char * nome = "Pedro Alvares";
    char nome[20];
    float preco = 0.0;
    int qtd = 0;
    const char * dados = "banana nanica 3.40 3";
    char final[100];
    sscanf(dados, "%s %f %d", nome, &preco, &qtd);
    sprintf(final, "Produto: %s, preco: %.2f, qtd: %d", nome, preco, qtd);
    puts(final);

    return 0;
}