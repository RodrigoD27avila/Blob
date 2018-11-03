#include <SDL.h>

int check_rect(SDL_Rect *rect, int x, int y)
{
	if (x >= rect->x && x <= (rect->x + rect->w)
		&& y >= rect->y && y <= (rect->y + rect->h)) {
		return 1;
	}

	return 0;
} 

int main()
{
	SDL_Surface *screen = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Video not initialized.\n");
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Set video mode failed.\n");
		exit(EXIT_FAILURE);
	}

	SDL_Event event;
	SDL_bool quit = SDL_FALSE;

	SDL_Rect rect = {10, 10, 30, 30};

	SDL_bool active = SDL_FALSE;
	int x, y;

	while (!quit) {

		int count = 0;	
		while (SDL_PollEvent(&event))
		{
			count += 1;
			if (event.type == SDL_MOUSEMOTION) {
				x = event.motion.x;
				y = event.motion.y;

				if (active) {
					rect.x = x;
					rect.y = y;
				}
				
			}

			if (event.type == SDL_MOUSEBUTTONDOWN)
				active = SDL_TRUE;
			
			if (event.type == SDL_MOUSEBUTTONUP)
				active = SDL_FALSE;

			if (event.type == SDL_QUIT)
				quit = SDL_TRUE;
		}
		SDL_FillRect(screen, &screen->clip_rect,
			SDL_MapRGB(screen->format, 0, 0, 0));

		if (active && check_rect(&rect, x, y)) {
			SDL_FillRect(screen, &rect,
				SDL_MapRGB(screen->format, 0xff, 0, 0xff));
		}
		else {

			SDL_FillRect(screen, &rect,
				SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
		}

		SDL_Flip(screen);
		SDL_Delay(15);

	}

	SDL_Quit();
	return 0;
}
