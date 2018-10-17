#include <stdio.h>

int main(){
    int vcont[10];
    int vdesl_size = 0;
    int cofre_size = 0;//operacoes
    scanf("%d %d", &cofre_size, &vdesl_size);
    int cofre[cofre_size];
    int vdesl[vdesl_size];

    for(int i = 0; i < cofre_size; i++) //1, <=
        scanf("%d", &cofre[i]);
    for(int i = 0; i < vdesl_size; i++)
        scanf("%d", &vdesl[i]);
    for(int i = 0; i < 10; i++)
        vcont[i] = 0;
        
    int i = 0;
    while(i != vdesl_size - 1){
        vcont[cofre[vdesl[i] - 1]] += 1;
        if(vdesl[i] < vdesl[i + 1])
            vdesl[i] += 1;
        else if(vdesl[i] > vdesl[i + 1])
            vdesl[i] -= 1;
        if(vdesl[i] == vdesl[i + 1])
            i++;
    }
    
    for(int i = 0; i < 9; i++)
        printf("%d ", vcont[i]);
    printf("%d\n", vcont[9]);
    
    puts("");
    return 0;
}
