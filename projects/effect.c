#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16


void apply_surface(int x, int y, SDL_Surface *src, SDL_Surface *dest,
	SDL_Rect *clip);

SDL_Surface *load_image(char *name);

void doeffect(SDL_Surface *src, SDL_Surface *dest)
{
	static int x;
	static int y;
	static int t;

	SDL_Rect clip;

	clip.x = 0;
	clip.y = y;
	clip.w = src->clip_rect.w;
	clip.h = 4;

	apply_surface(t+x, y, src, dest, &clip);

	y += 4;

	if (y >= src->clip_rect.w) {
		y = 0;
		t += 2;
		x = 0;
	}
	x += 2;
}

SDL_Surface *load_image(char *name)
{
	SDL_Surface *image    = NULL;
	SDL_Surface *optimage = NULL;

	image = SDL_LoadBMP(name);
	if (image == NULL) {
		fprintf(stderr, "Cannot load BMP: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	optimage = SDL_DisplayFormat(image);
	SDL_FreeSurface(image);

	if (optimage == NULL) {
		fprintf(stderr, "Cannot optimize image: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	return optimage;
}

void apply_surface(int x, int y, SDL_Surface *src, SDL_Surface *dest,
	SDL_Rect *clip)
{
	SDL_Rect offset = {0};
	offset.x = x;
	offset.y = y;

	if (SDL_BlitSurface(src, clip, dest, &offset) < 0) {
		fprintf(stderr, "Cannot blit surface: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{

	SDL_Surface *screen = NULL;
	SDL_Surface *image  = NULL;
	
	atexit(SDL_Quit);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Cannot init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
		SDL_SWSURFACE);

	if (screen == NULL) {
		fprintf(stderr, "Cannot set video mode: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	image = load_image("teste.bmp");

	SDL_Event event;
	SDL_bool  quit = SDL_FALSE;

	while (!quit) {
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {
				quit = SDL_TRUE;
			}		
		}

		doeffect(image, screen);

		if (SDL_Flip(screen) < 0) {
			fprintf(stderr, "Cannot flip screen: %s\n",
				SDL_GetError());
			exit(EXIT_FAILURE);
			
		}
//		SDL_Delay(40);
	}

	SDL_Quit();

	return 0;
}
