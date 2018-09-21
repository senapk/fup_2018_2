#include "xpaint.h"
#include <stdio.h>

const int LARGURA = 800;
const int ALTURA = 600; //melhor opcao que o define
//const int LADO = 100;
#define LADO 100

typedef struct{
    int x;
    int y;
    XColor cor;
} Item;

Item andar(Item cobra, char op){
    if(op == 'd')
        cobra.x += LADO;
    else if(op == 'a')
        cobra.x -= LADO;
    else if(op == 'w')
        cobra.y -= LADO;
    else if(op == 's')
        cobra.y += LADO;
    cobra.x = cobra.x % LARGURA;
    cobra.y = cobra.y % ALTURA;
    if(cobra.x < 0)
        cobra.x += LARGURA;
    if(cobra.y < 0)
        cobra.y += ALTURA;
    return cobra;
}

int main(){
    x_open(LARGURA, ALTURA);

    Item cobra;
    cobra.x = 0;
    cobra.y = 0;
    cobra.cor = GREEN;

    Item maca = {3 * LADO, 3 * LADO, RED};

    char op;
    while(1){
        x_clear(BLACK);

        xs_color(GREEN);
        xd_filled_rect(cobra.x, cobra.y, cobra.x + LADO, cobra.y + LADO);
        xs_color(RED);
        xd_filled_circle(maca.x + LADO/2, maca.y + LADO/2, LADO/2);
        
        x_save("main");

        scanf(" %c", &op);
        cobra = andar(cobra, op);

        if(cobra.x == maca.x && cobra.y == maca.y){
            maca.x = (rand() % (LARGURA / LADO)) * LADO;
            maca.y = (rand() % (ALTURA / LADO)) * LADO;
        }
    }

    x_close();
    return 0;
}