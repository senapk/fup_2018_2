#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int x, y;
} v2d;

//retorna o primeiro indice onde achou value ou 
//ou -1 se nao encontrar
int find_vet(int vet[], int size, int value){
    for(int i = 0; i < size; i++)
        if(vet[i] == value)
            return i;
    return -1;
}

//c99
//retorna posicao que encontrou ou {-1, -1}
/* v2d find_mat(v2d size, int mat[][size.x], int value){
    for(int l = 0; l < size.y; l++){
        for(int c = 0; c < size.x; c++){
            if(mat[l][c] == value){
                return (v2d){c, l};
            }
        }
    }
    return (v2d){-1, -1};
} */

//c99
//retorna posicao que encontrou ou {-1, -1}
v2d find_mat(int * mat, int nl, int nc, int value){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l * nc + c] == value){
                return (v2d){c, l};
            }
        }
    }
    return (v2d){-1, -1};
}

void infectar_um(int * mat, int nl, int nc, int l, int c, int ger){
    for(int y = l - 1; y <= l + 1; y++){
        for(int x = c - 1; x <= c + 1; x++){
            if((y >= 0) && (y < nl) && (x >=0) && (x < nc)){
                if(mat[y * nc + x] == 0)
                    mat[y * nc + x] = ger + 1;
            }
        }
    }
}

void infectar(int * mat, int nl, int nc, int ger){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l * nc + c] == ger){
                //printf("achei zumbi %d %d\n", l, c);
                infectar_um(mat, nl, nc, l, c, ger);
            }
        }
    }
}

void mat_show(int * mat, int nl, int nc){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%d", mat[l * nc + c]);
        puts("");
    }
}

int main(){
/*     //c89
    v2d pos0 = {3, 4};

    //c99
    v2d pos1 = {.x = 3, .y = 4};
    v2d pos2 = {.y = 6, .x = 2};

    //c99
    v2d pos;
    pos = (v2d){3, 4}; */
    srand(0);
    int nl = 6;
    int nc = 30;
    int mat[nl * nc];

    for(int i = 0; i < nl * nc; i++)
        mat[i] = 0;

    int zumbis = 5;
    for(int i = 0; i < zumbis; i++){
        int l = rand() % nl;
        int c = rand() % nc;
        mat[l * nc + c] = 1;
    }

    int ger = 1;
    while(find_mat(mat, nl, nc, 0).x != 1){
        printf("\n%d\n", ger);
        infectar(mat, nl, nc, ger);
        ger++;
        mat_show(mat, nl, nc);
        printf("###########################\n\n");
        getchar();
    }
}

