# include <stdio.h>
# include <stdlib.h>
int main(int argc , char *argv []) {
    int soma = 0;
    for (int k = 0; k < argc; k++)
        soma += atoi(argv[k]);
    printf("Soma: %d\n", soma);
}