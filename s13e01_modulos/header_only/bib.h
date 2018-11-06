//DECLARACOES
//#pragma once

#ifndef BIB_H //códigos de guarda
#define BIB_H

typedef struct {
    int x;
    int y;
} Par;

extern int MAX;
int soma(int a, int b);

#endif


#ifdef BIB_FULL

int MAX = 100;
int soma(int a, int b){
    return a + b;
}
#endif