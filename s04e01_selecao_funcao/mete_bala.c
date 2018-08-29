#include <stdio.h>
#include <math.h>

double quad(double x){
    return x * x;
}

double calc_distancia(double x1, double y1, double x2, double y2){
    return sqrt(quad(x2 - x1) + quad(y2 - y1));
}

int main(){
    double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    double resp = calc_distancia(x1, y1, x2, y2);
    printf("%lf\n", resp);
    
    return 0;
}