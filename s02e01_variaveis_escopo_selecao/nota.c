#include <stdio.h>

int main(){
    float nota1 = 0.f;
    float nota2 = 0.f;
    puts("Digite a primeira e segunda nota");
    scanf("%f %f", &nota1, &nota2);
    float media = (nota1 + nota2) / 2;
    printf("Sua media das aps foi %f\n", media);

    if(media >= 7)
        puts("aprovado");
    else if(media < 4)
        puts("reprovado");
    else{
        puts("voce ficou de final\nDigite a nota da final");
        float nota_final = 0.f;
        scanf("%f", &nota_final);
        media = (media + nota_final) / 2;
        if(media > 4.99)
            puts("aprovado final");
        else
            puts("reprovado final");
        printf("Media final %f\n", media);
    }
}


/* int frutas = 51
int cesta = 10
viagens = frutas / cesta
if(frutas % cesta > 0)
    viagens += 1
tempo_total = viagens * 60 + frutas * 5

30 segundos ir 
30 segundos voltar 
5 segundos para cada fruta  */

