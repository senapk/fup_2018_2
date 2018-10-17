#ifndef KSDL_H
#define KSDL_H
#include <stdint.h> //Uint32

typedef uint32_t Time;

void k_init(int largura, int altura);
int  k_window_open();
void k_set_color(int r, int g, int b);
void k_clear();
void k_plot(int x, int y);
void k_display();
void k_close();

#endif


#ifndef KSDL_H_ONLY

#include <stdlib.h>
#include <SDL2/SDL.h>

static SDL_Renderer *renderer;
static SDL_Window *window;
static Time _time;

void k_reset_timer(){
    _time = SDL_GetTicks();
}

Time k_get_timer(){
    return SDL_GetTicks() - _time;
}

void k_init(int largura, int altura){
    SDL_Init(SDL_INIT_VIDEO); //inicia o video
    SDL_CreateWindowAndRenderer(largura, altura, 0, &window, &renderer); //inicia janela e render
}

void k_set_color(int r, int g, int b){
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void k_clear(){
    SDL_RenderClear(renderer);
}

void k_plot(int x, int y){
    SDL_RenderDrawPoint(renderer, x, y);
}

void k_display(){
    SDL_RenderPresent(renderer);
}

void k_close(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

#endif
