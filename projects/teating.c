#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#define WIDTH  640
#define HEIGHT 480
#define BPP    32
#define FPS    60

int main()
{
	SDL_Surface *screen = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		fprintf(stderr, "Unable to init SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Unable to set video mode: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
		
	}

	Uint32 start, end;
	SDL_Event event;

	SDL_bool quit = SDL_FALSE;
	while (!quit) {
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_q) {
					exit = SDL_TRUE;
				}
			}
		}

		
	}
	
}
