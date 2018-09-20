#include "xpaint.h"
#include <stdio.h>
int main(){
    x_open(800, 500);
    int x = 0, y = 0, l = 50;

    while(1){
        x_clear(BLACK);
        xd_filled_rect(x, y, x + l, y + l);
        x_save("main");
        getchar();
    }
    x_close();
    return 0;
}