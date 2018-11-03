#include <SDL.h>

/* main surface */
static SDL_Surface *screen;

void putpixel(int x, int y, int color)
{
	Uint32 *ptr = (Uint32 *)screen->pixels;
	int lineoffset = y * (screen->pitch / 4);
	ptr[lineoffset + x] = color;
}

void render()
{
	/* lock surface if needed */
	if (SDL_MUSTLOCK(screen)) {
		if (SDL_LockSurface(screen) < 0) {
			return;
		}
	}

	/* ask sdl for the time in milliseconds */
	Uint32 ticks = SDL_GetTicks();

	/* some variables */
	int i, j, yofs, ofs;

	/* draw to screen */
	yofs = 0;
	for (i=0; i<480; i++) {
		for (j=0, ofs = yofs; j<640; j++, ofs++) {
			((Uint32 *)screen->pixels)[ofs] =
			(i * i) + (j * j) + ticks;
		}

		yofs += screen->pitch / 4;
	}

	/* unlock if needed */
	if (SDL_MUSTLOCK(screen)) {
		SDL_UnlockSurface(screen);
	}

	putpixel(10, 10, 0xff0000);
	putpixel(11, 10, 0xff0000);
	putpixel(10, 11, 0xff0000);
	putpixel(11, 11, 0xff0000);

	/* tell the sdl to update screen */
	SDL_UpdateRect(screen, 0, 0, 640, 480);
}


int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "unable to init sdl: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	
	if (screen == NULL) {
		fprintf(stderr, "unable to set video mode:%s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_bool  quit  = SDL_FALSE;
	SDL_Event event = {0};

	while (!quit) {
		render();

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = SDL_TRUE;
				}
				break;

			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			}
		}
	}

	return 0;
}
