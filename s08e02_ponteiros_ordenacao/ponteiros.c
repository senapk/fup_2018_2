#include <stdio.h>

/*
tipo  | nome | lugar
int   |   a  | 100 - 103
int*  |   p  | 104 - 111
0
1
2
3
...
100 - 00000000
101 - 00000000
102 - 00000000
103 - 00000101 - 5 em binario
104 - 00000000
111 - 01100100 - 100 em binari0
*/


/*

    z 300 9
    x 304 7

*/

int swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}


int main(){
    unsigned int a = 5;
    unsigned int *p = &a;

    printf("endereco      de a = %p\n", &a);
    printf("valor         de a = %d\n",  a);
    printf("endereco      de p = %p\n", &p);
    printf("valor         de p = %p\n",  p);
    printf("indo para  a via p = %d\n", *p);

    /*
    c 200 30
    k 204 200
    y 212 200
    */

    int c = 7;
    int *k = NULL, *y = NULL;
    k = &c;
    y = k;
    print("%d", *y);

    *y = 30;

    int z = 7;
    int x = 9;
    swap(&z, &x);//9 e 7

    return 0;
}