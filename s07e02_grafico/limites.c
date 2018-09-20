#include <stdio.h>

int main(){
    int qtd = 0;
    int inf = 0;
    int sup = 0;
    int cont = 0;
    int value = 0;
    scanf("%d %d %d", &qtd, &inf, &sup);
    for(int i = 0; i < qtd; i++){
        scanf("%d", &value);
        if((inf <= value) && (value <= sup))
            cont += 1;
    }
    printf("%d", cont);
}