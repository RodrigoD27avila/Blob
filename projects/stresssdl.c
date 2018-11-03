#include <stdio.h>
#include <stdlib.h>


#include <SDL.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen = SDL_SetVideoMode(640, 480, 32,
		SDL_SWSURFACE | SDL_DOUBLEBUF);
	
	SDL_Surface *sprite = SDL_LoadBMP("sprite.bmp");
	SDL_Surface *optspt = SDL_DisplayFormat(sprite);

	SDL_Event event;
	SDL_bool  quit = SDL_FALSE;

	Uint32 start, curr;

	while (!quit) {

		start = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = SDL_TRUE;
			}
		}

		int i;
		for (i=0; i<15000; i++) {
			SDL_Rect rect = {rand() % 640, rand() % 480, 0, 0};
			SDL_BlitSurface(optspt, NULL,
				screen, &rect);
		}

		SDL_Flip(screen);
		//SDL_UpdateRect(screen, 0, 0, 100, 100);

		curr = SDL_GetTicks();

		if ((curr - start) < (1000.0f / 60.0f)) {
			SDL_Delay((1000.0f / 60.0f) - (curr - start));
		}
		else {
			
			printf("Ooops %i sprites is to much.\n", i);
			printf("%f\n", ((1000.0f / 60.0f) - (curr - start)));
		}

	}

	return 0;
}
