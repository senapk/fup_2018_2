#include "xpaint.h"
int main(){
    x_open(600, 600);
    xs_color(GREEN);       
    xd_filled_circle(300, 300, 150);
    x_save("mickey");
    x_close();
    return 0;
}
