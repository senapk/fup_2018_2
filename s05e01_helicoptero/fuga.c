#include <stdio.h>

int main(){
    int h; 
    int f;
    int p;
    int d;
    scanf("%d %d %d %d", &h, &p, &f, &d);
    
    while(1){
        /*
        f += d;
        if(f == 16)
            f = 0;
        else if(f == -1)
            f = 15;
        */
        //opcao 2
        f = ((f + d + 16) % 16);
        
        if(f == p){
            puts("N");
            break;
        } else if (f == h){
            puts("S");
            break;
        }
        
    }


    return 0;
}