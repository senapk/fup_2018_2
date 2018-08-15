#include <stdio.h>
#include <stdlib.h>

// exemplo da declaração da função scanf
// int scanf(const char * format, ...);

int main () {

    int i; //um lugar da memoria que eu posso colocar um inteiro
    //e posso acessá-lo sempre através do nome 'i'
    const int b = 6; //b sera sempre 6 pro resto de sua vida
    (void) b; //so pro compilador nao dizer que nao estou usando b

    float f = 3.14;
    char c;
    char palavra[20]; //string
    char linha[100];

    puts("Digite um inteiro, um caractere, um float e uma palavra");
    
    //leia um inteiro e um float
    //guarde no endereço de i o primeiro
    //guarde no endereço de f o segundo
    scanf ("%d %c %f", &i, &c, &f);

    scanf("%s", palavra);//uma palavra

    //sobrou um \n no buffer
    getchar();

    puts("Digite seu nome completo");
    
    fgets(linha, sizeof(linha), stdin); //pega ate encontrar um \n, mas descarta o \n

    puts("Vou escrever na tela");
    printf("%d - %c - %f - %s - %s\n", i, c, f, palavra, linha);
    
    int   idade = 19;
    float valor = 5.4321;

    printf("%5d %.2f\n", valor);//00019 5.43

    int desconto = 10;
    printf("promocao de %d%% de desconto");
    //promocao de 10% de desconto

    return 0;
}