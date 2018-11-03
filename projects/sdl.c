#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

int main()
{
    SDL_Window   *window = NULL;
    SDL_Renderer *renderer = NULL;

   if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Unable to init SDL: %s",
            SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("SDL app",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (window == NULL) {
        fprintf(stderr, "Unable to create a window: %s",
            SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Unable to create a renderer: %s",
            SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return 0;
}
