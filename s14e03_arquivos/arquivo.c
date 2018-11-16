#include <stdio.h>

int main(){
    FILE * file_in;
    FILE * file_out;
    FILE * file_log;
    file_in = fopen("input.txt", "r");
    file_out = fopen("saida.txt", "w");
    file_log = fopen("log.txt", "a");

    if(file_in == NULL){
        puts("arquivo nao existe");
        return 1;
    }
    int a = 0;
    int b = 0;
    fscanf(file_in, "%d %d", &a, &b);
    fprintf(file_out, "a soma eh %d\n", (a + b));
    fprintf(file_log, "a soma eh %d\n", (a + b));
    fclose(file_in);
    fclose(file_out);
    fclose(file_log);
    return 0;
}