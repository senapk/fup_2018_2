#include <stdio.h>
#include <string.h>

int main(){
    /* int vet[20];
    int size = sizeof(vet) / sizeof(int);
    for(int i = 0; i < size; i++)
        vet[i] = i;

     */

    FILE * file_bin = fopen("binario.bin", "wb");
    int a = 5;
    int b = 7;
    int c = 3;
    fwrite(&a, sizeof(int), 1, file_bin);
    fwrite(&b, sizeof(int), 1, file_bin);
    fwrite(&c, sizeof(int), 1, file_bin);
    fclose(file_bin);

    file_bin = fopen("binario.bin", "rb");
    int vet[3];
    fread(vet, sizeof(int), 3, file_bin);
    for(int i = 0; i < 3; i++)
        printf("%d ", vet[i]);
    puts("acabou");
    fclose(file_bin);

    char frase_motivacional[1000];
    fgets(frase_motivacional, 1000, stdin);
    int slen = strlen(frase_motivacional);
    FILE * frase_bin = fopen("frase.bin", "wb");
    
    fwrite(&slen, sizeof(int), 1, frase_bin);
    fwrite(frase_motivacional, sizeof(char), slen, frase_bin);
    fclose(frase_bin);

    frase_bin = fopen("frase.bin", "rb");
    int nchar = 0;
    fread(&nchar, sizeof(int), 1, frase_bin);
    char frase_reconstituida[nchar + 1];
    fread(frase_reconstituida, sizeof(char), nchar, frase_bin);
    frase_reconstituida[nchar] = '\0';
    fclose(frase_bin);
    puts(frase_reconstituida);
    








    return 0;
}