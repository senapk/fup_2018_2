#include "xpaint.h"
#include <stdio.h>
//wget https://raw.githubusercontent.com/senapk/xpaint/master/xpaint.h

int main(){
    x_open(600, 600);
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    char op = '\0';
    int i = 0;
    while(1){
        __fpurge(stdin);
        puts("digite l para linha, c para circulo, q para quadrado, b para bezier");
        scanf(" %c", op); //esse espaço antes do c é importante para pular os whitespaces
        if(op == 'l'){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            xd_line(x1, y1, x2, y2);
        }
        printf("%d\n", i++);
        x_save("linhas");
    }
    x_close();
    return 0;
}