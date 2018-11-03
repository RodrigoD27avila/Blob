#include <SDL.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

	SDL_Window *window = SDL_CreateWindow(NULL,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window,
		-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture *sprt = SDL_CreateTextureFromSurface(renderer,
		SDL_LoadBMP("sprite.bmp"));

	if (!sprt) {
		exit(EXIT_FAILURE);
	}

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;

	Uint32 start, curr;

	while (!quit) {

		start = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = SDL_TRUE;
			}
		}


//		SDL_RenderClear(renderer);

		int i;
		for (i=0; i<15000; i++) {
			SDL_Rect pos = {rand() % 640, rand() % 480, 92, 92};
			//SDL_QueryTexture(sprt, NULL, NULL, &pos.x, &pos.y);
			SDL_RenderCopy(renderer, sprt, NULL, &pos);
		}

		SDL_RenderPresent(renderer);

		curr = SDL_GetTicks();

		if ((curr - start) < (1000.0f / 60.0f)) {
			SDL_Delay((1000.0f / 60.0f) - (curr - start));
		}
		else {
			
			printf("Ooops %i sprites is to much.\n", i);
			printf("%f\n", ((1000.0f / 60.0f) - (curr - start)));
		}
	}

	SDL_Quit();
	return 0;
}
