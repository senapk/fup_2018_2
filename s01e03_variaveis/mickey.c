#include "xpaint.h"

void desenhar_mickey(int xd, int yd, float f){
    xd_circle(f * 300 + xd,f * 300 + yd,f * 150);//cabeça
    xd_circle(f * 150 + xd,f * 140 + yd,f * 70); //orelha e
    xd_circle(f * 450 + xd,f * 140 + yd,f * 70); // orelha d
    
    xd_ellipse(f * 250 + xd,f * 210 + yd,f * 280 + xd,f * 290 + yd); //olho e
    xd_filled_ellipse(f * 255 + xd,f * 250 + yd,f * 275 + xd,f * 290 + yd); //olho bila
    
    
    xd_ellipse(f * 315 + xd,f * 210 + yd,f * 345 + xd,f * 290 + yd); //olho d
    xd_filled_ellipse(f * 320 + xd,f * 250 + yd,f * 340 + xd,f * 290 + yd); //olho bila
    
    
    xd_bezier(f * 200 + xd,f * 350 + yd,f * 300 + xd,f * 400 + yd,f * 400 + xd,f * 350 + yd);
    xd_bezier(f * 200 + xd,f * 350 + yd,f * 300 + xd,f * 470 + yd,f * 400 + xd,f * 350 + yd);
    xd_filled_ellipse(f * 250 + xd,f * 300 + yd,f * 350 + xd,f * 350 + yd);
}

int main(){
    int largura = 600, altura = 500;
    /* cria um bitmap de 600x600 */
    int xd = 0;
    int yd = 0;
    float f = 0.5;
    x_open(largura, altura); 
    desenhar_mickey(0, 0, 1);
    x_save("mickey");
    /* libera os recursos alocados */
    x_close();
    return 0;
}
