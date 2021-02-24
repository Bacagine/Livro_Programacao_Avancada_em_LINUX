// Compilar com gcc grid.c -o grid `sdl-config --flags` `sdl-config --libs`

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#define LARGURA 256
#define ALTURA  256
#define STEP LARGURA/8

int main(void){
	
    SDL_Surface *screen;
    SDL_Event event;
    SDL_Keysym keysym;
    Uint16 *tela;
    int x, y, offset;
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_LockSurface(screen);
    
    tela = (Uint16 *) screen->pixels;
    
    // Desenha eixos horizontais
    for(x = 0; x < LARGURA; x = x + STEP){
        for(y = 0; y < ALTURA; y++){
            offset = (screen->pitch / 2 * y + x);
            // cor branca em 16 bits
            tela[offset] = 65535;
        }
    }
    
    // Desenha eixos verticais
    for(x = 0; x < LARGURA; x++){
        for(y = 0; y < ALTURA; y = y + STEP){
            offset = (screen->pitch / 2 * y + x);
            // cor branca em 16 bits
            tela[offset] = 65535;
        }
    }
    SDL_UnlockSurface(screen);
    
    SDL_UpdateTexture(screen, 0, 0, 0, 0);
    while(SDL_WaitEvent(&event) != 0){
        switch(event.type){
            case SDL_MOUSEMOTION:
            fprintf(stderr, "pos: %i,%i\n", event.motion.x, event.motion.y);
            break;
            case SDL_KEYDOWN:
                if(keysym.sym == SDLK_q){
                fprintf(stderr,"Saindo..\n");
                exit(0);
                }
                break;
        }
    SDL_UpdateRect(screen, 0, 0, 0, 0);
    }
    
	return 0;
}

