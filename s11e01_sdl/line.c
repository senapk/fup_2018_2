#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "help.h"
#include <stdbool.h>

typedef struct{
    float x;
    float y;
    float vx;
    float vy;
    int r; //red
    int g; //green
    int b; //blue
} Ponto;

void show_square(Ponto alien, int lado){
    k_set_color(alien.r, alien.g, alien.b);

    for (int l = 0; l < lado; ++l)
        for(int c = 0; c < lado; ++c)
            k_plot(alien.x + c, alien.y + l);
    
    k_set_color(255, 255, 255);

    for(int l = 0; l < lado; ++l){
        k_plot(alien.x, alien.y + l);
        k_plot(alien.x + lado, alien.y + l);
    }

    for(int c = 0; c < lado; ++c){
        k_plot(alien.x + c, alien.y);
        k_plot(alien.x + c, alien.y + lado);
    }
}

void swap(int * a, int * b){
    int c = *a;
    a[0] = b[0];
    b[0] = c;
}

void quicar_dentro(Ponto * alien, int lado, int largura, int altura){
    if(alien->y + lado > altura){
        alien->y = altura - lado - 1;
        alien->vy *= -1;
    }
    if(alien->x < 0){
        alien->x = 0;
        alien->vx *= -1;
    }
    if(alien->y < 0){
        alien->y = 0;
        alien->vy *= -1;
    }
    if(alien->x + lado > largura){
        alien->x = largura - lado;
        alien->vx *= -1;        
    }
}

int main(void) {
    srand(time(NULL));
    bool is_open = true;
    int largura = 800;
    int altura = 600;
    k_init(largura, altura);
    int qtd = 10;
    int lado = 50;
    float grav = 0.1;
    Ponto aliens[qtd];
    for(int i = 0; i < qtd; i++){
        aliens[i].x = rand() % (largura - lado);
        aliens[i].y = rand() % (altura - lado);
        aliens[i].vx = (rand() % 11) - 5;
        aliens[i].vy = (rand() % 11) - 5;
        aliens[i].r = rand() % 256;
        aliens[i].g = rand() % 256;
        aliens[i].b = rand() % 256;
    }

    SDL_Event evento;

    while (is_open) {
        k_set_color(50, 50, 50); //muda cor para preto
        k_clear(); //limpa a tela
        k_set_color(255, 0, 0);//muda cor para vermelho
        
        while(SDL_PollEvent(&evento)){
            if(evento.type == SDL_QUIT)
                is_open = false;
            if(evento.type == SDL_KEYDOWN){
                if(evento.key.keysym.sym == SDLK_UP)
                    grav -= 0.1; 
                else if(evento.key.keysym.sym == SDLK_DOWN)
                    grav += 0.1; 
            }            
        }

        if(k_get_timer() > 10){
        /*     alien.x += ((rand() % 3) - 1);
            alien.y += ((rand() % 3) - 1); */
            for(int i = 0 ; i < qtd; i++){
                aliens[i].vy += grav;
                
                aliens[i].x += aliens[i].vx;
                aliens[i].y += aliens[i].vy;
            }
            k_reset_timer();
        }
        
        for(int i = 0 ; i < qtd; i++)
            quicar_dentro(&aliens[i], lado, largura, altura);
    
        for(int i = 0 ; i < qtd; i++)
            show_square(aliens[i], lado);       

        k_display();
    }
    k_close();
    return 0;
}