#include <stdio.h>
#include <math.h>

typedef struct{
    float delta;
    float r1;
    float r2;
} Raizes;

Raizes calcular_raizes(float a, float b, float c){
    Raizes sacola;

    sacola.delta = b * b - 4 * a * c;
    sacola.r1 = (-b + sqrt(sacola.delta))/(2 * a); 
    sacola.r2 = (-b - sqrt(sacola.delta))/(2 * a);
    return sacola;
}


int main(){
    float a = 0.0, b = 0.0, c = 0.0;
    scanf("%f %f %f", &a, &b, &c);
    Raizes sacola  = calcular_raizes(a, b, c);

    if(sacola.delta < 0)
        puts("nao ha raiz real");
    else if(sacola.delta == 0){
        printf("%.2f\n", sacola.r1);
    }else
        printf("%.2f %.2f\n", sacola.r1, sacola.r2);
    return 0;
}