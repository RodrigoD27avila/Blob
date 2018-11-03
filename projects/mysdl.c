#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "unable to init SDL.\n");
		exit(EXIT_FAILURE);
	}

	SDL_Surface *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 24,
		SDL_SWSURFACE);

	if (screen == NULL) {
		fprintf(stderr, "unable to init screen.\n");
		exit(EXIT_FAILURE);
	}

	SDL_bool continue_loop = SDL_TRUE;

	while (continue_loop) {

		SDL_Delay(120);

		if (SDL_Flip(screen) < 0) {
			fprintf(stderr, "unable to flip screen.");
			continue_loop = SDL_FALSE;
		}
	}

	SDL_Delay(3000);

	SDL_FreeSurface(screen);
	SDL_Quit();
}
