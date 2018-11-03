#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "graphics.h"
#include "memory.h"
#include "settings.h"
#include "window.h"

static SDL_Surface *OptimizeSurface(SDL_Surface *surface);
static SDL_Surface *CreateEmptySurface(Uint16 width, Uint16 height);

static SDL_Surface *CreateEmptySurface(Uint16 width, Uint16 height)
{
	SDL_Surface *surface;
	Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
#else
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif

	surface = SDL_CreateRGBSurface(0, width, height, 32,
		rmask, gmask, bmask, amask);

	if (surface == NULL) {
	        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        	exit(EXIT_FAILURE);
	}

	return surface;
}

SDL_Texture *image_CreateTexture(SDL_Surface *image, SDL_Rect *clip_rect)
{
	// create empty surface
	SDL_Surface *suface = CreateEmptySurface(clip_rect->w, clip_rect->h);

	// optimize furface
	SDL_Surface *optimized = OptimizeSurface(suface);
	SDL_FreeSurface(suface);

	// destination rect
	SDL_Rect destrect   = {0, 0, clip_rect->w, clip_rect->h};

	// copy pixels
	if (SDL_BlitSurface(image, clip_rect, optimized, &destrect) < 0) {
		fprintf(stderr, "Unable to blit surface: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// create texture
	SDL_Texture *texture = SDL_CreateTextureFromSurface(
		window_GetMainRenderer(), optimized);

	if (texture == NULL) {
		fprintf(stderr, "Unable to create texture: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_FreeSurface(optimized);

	return texture;
}

static SDL_Surface *OptimizeSurface(SDL_Surface *surface)
{
	/* get main window surface */
	SDL_Surface *screen = SDL_GetWindowSurface(window_GetMainWindow());

	/* optimize surface */
	SDL_Surface *optimized = SDL_ConvertSurface(surface,
		screen->format, 0);

	if (optimized == NULL) {
		fprintf(stderr, "[image] Unable to optimize surface: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	return optimized;
}


SDL_Surface *image_Load(const char *filename)
{
	SDL_Surface *surface    = IMG_Load(filename);
	SDL_Surface *optimized  = OptimizeSurface(surface);

	SDL_FreeSurface(surface);

	return optimized;
}
