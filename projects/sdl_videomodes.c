#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Rect **modes = SDL_ListModes(NULL, SDL_SWSURFACE|SDL_FULLSCREEN);

	if (modes == (SDL_Rect **)0) {
		fprintf(stderr, "falhou!!\n");
		exit(EXIT_FAILURE);
	}

	if (modes == (SDL_Rect **)-1) {
		printf("All modes avaliable");
		SDL_Quit();
		return 0;
	}

	int i;
	for (i=0; modes[i]; i++) {
		printf("%d x %d\n", modes[i]->w, modes[i]->h);
	}

	SDL_Quit();
	return 0;
}
