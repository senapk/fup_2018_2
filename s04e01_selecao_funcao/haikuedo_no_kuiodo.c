#include <stdio.h>

int main(){
    char tipo = 0;
    int forca = 0;

    scanf("%c %d", &tipo, &forca);
    
    int valor = tipo == 'b' ? 20 : 18;

    float poder = ((forca * valor) - 80) / 10.0;
    
    if(poder < 150)
        puts("Fraco, nem passou");
    else if(poder < 180)
        puts("Perfeito");
    else if(poder < 210)
        puts("Satisfeito");
    else
        puts("Muito forte, bola fora");