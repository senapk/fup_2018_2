#include <stdio.h>
#include <stdlib.h>

int str2int(char * str){
    int acc = 0;
    for(int i = 0; str[i] != '\0'; i++)
        acc = acc * 10 + str[i] - '0';
    return acc;
}

int main(int argc, char * argv[]){
    if(argc < 3){
        printf("use ./soma _num _num");
        return 1;
    }
    int num1 = str2int(argv[1]);
    int num2 = atoi(argv[2]);

    printf("Soma = %d\n", (num1 + num2));
    return 0;
}