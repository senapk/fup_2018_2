#include "xpaint.h"
#include <stdio.h>
int main(){
    int largura = 800;
    int altura = 600;
    x_open(800, 600);
    int x = 0, y = 0, l = 100;
    int mx = 0, my = 0;
    char op;
    while(1){
        x_clear(BLACK);

        xs_color(GREEN);
        xd_filled_rect(x, y, x + l, y + l);
        xs_color(RED);
        xd_filled_rect(mx, my, mx + l, my + l);
        
        x_save("main");

        scanf(" %c", &op);
        if(op == 'd')
            x += l;
        else if(op == 'a')
            x -= l;
        else if(op == 'w')
            y -= l;
        else if(op == 's')
            y += l;

        x = x % largura;
        y = y % altura;
        if(x < 0)
            x += largura;
        if(y < 0)
            y += altura;

        if(x == mx && y == my){
            mx += l;
            my += l;
        }
    }

    //mx = rand() % (largura / l);
    //my = rand() % (altura / l);

    x_close();
    return 0;
}