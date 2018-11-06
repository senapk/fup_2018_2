#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {LEFT = 0, UP, RIGHT, DOWN} Direcao;

typedef struct{
    int x;
    int y;
    SDL_Color cor;
} Elem;

int    DESLX[] = {-1, 0, +1, 0};
int    DESLY[] = {0, -1, 0, +1};

SDL_Window * window; //janela
SDL_Renderer * renderer; //renderizador do buffer
int largura = 800;
int altura = 600;
int lado = 50;

void draw_square(int x, int y, int lado);
Elem criar_maca();


#define BLACK 0, 0, 0

int main()
{
    srand(time(NULL));
    int timer = SDL_GetTicks();
    // init SDL
    SDL_Init(SDL_INIT_VIDEO);//inicia o vídeo
    SDL_CreateWindowAndRenderer(largura, altura, 0, &window, &renderer);

    //variaveis do quadrado
    Elem cobra[100];
    cobra[0] = (Elem){200, 200, {255, 0, 0, 255}};
    int gomos = 1;

    Elem maca = criar_maca();

    Direcao direcao = RIGHT;

    // gerenciar eventos
    bool is_open = true;
    SDL_Event event;
    while(is_open){
        while(SDL_PollEvent(&event)){ 
            if(event.type == SDL_QUIT)
                is_open = false;
            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.sym == SDLK_UP)
                    direcao = UP; 
                else if(event.key.keysym.sym == SDLK_DOWN)
                    direcao = DOWN;
                else if(event.key.keysym.sym == SDLK_LEFT)
                    direcao = LEFT;
                else if(event.key.keysym.sym == SDLK_RIGHT)
                    direcao = RIGHT;
            }
        }

        if(SDL_GetTicks() - timer > 50){ //passou meio segundo
            timer = SDL_GetTicks(); //reseta tempo
            
            for(int i = gomos - 1; i > 0; i--){
                cobra[i].x = cobra[i - 1].x;
                cobra[i].y = cobra[i - 1].y;
            }
            cobra[0].x += DESLX[direcao] * lado;
            cobra[0].y += DESLY[direcao] * lado;  
        }

        //come a maca
        if(cobra[0].x == maca.x){
            if(cobra[0].y == maca.y){
                cobra[gomos] = maca;
                gomos += 1;
                maca = criar_maca();
            }
        }




        //limpa a tela
        SDL_SetRenderDrawColor(renderer, BLACK, 255); //muda cor pra preto
        SDL_RenderClear(renderer); //limpa a tela
        //desenha os trambolhos

        SDL_SetRenderDrawColor(renderer, maca.cor.r, maca.cor.g, maca.cor.b, 255); //muda cor pra vermelho
        draw_square(maca.x, maca.y, lado); //desenha um quadrado

        for(int i = 0; i < gomos; i++){
            SDL_SetRenderDrawColor(renderer, cobra[i].cor.r, cobra[i].cor.g, cobra[i].cor.b, 255); //muda cor pra vermelho
            draw_square(cobra[i].x, cobra[i].y, lado); //desenha um quadrado
        }
        //mostra a tela
        SDL_RenderPresent(renderer); //mostra o buffer na tela
    }
 
    // liberando recursos SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
 
    return 0;
}

void draw_square(int x, int y, int lado){
    for (int l = 0; l < lado; ++l)
        for(int c = 0; c < lado; ++c)
            SDL_RenderDrawPoint(renderer, x + c, y + l); //plota esse pixel
}

Elem criar_maca(){
    Elem maca;
    maca.x = (rand() % (largura / 50)) * 50;
    maca.y = (rand() % (altura / 50)) * 50;
    maca.cor.r = rand() % 256;
    maca.cor.g = rand() % 256;
    maca.cor.b = rand() % 256;
    maca.cor.a = 255;
    return maca;
}