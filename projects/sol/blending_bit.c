#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL.h>
const unsigned char sprite[] = {
	1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,
	1,1,0,0,0,0,0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0,
	0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,1,1,0,1,1,0,0,0,0,
	0,0,0,0,1,1,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,
	0,0,0,0,1,1,0,1,1,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0,
	0,0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,
	0,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,
	1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,
};

/* main surface */
static SDL_Surface *screen;
static Uint32 	   *tempbuf;

void drawsprite(int x, int y, unsigned int color)
{
	int i, j, c, yofs;
	yofs = y * (screen->pitch / 4) + x;
	for (i = 0, c = 0; i < 16; i++) {
		for (j = 0; j < 16; j++, c++) {
			if (sprite[c]) {
				((Uint32 *)screen->pixels)[yofs + j] = color;
			}
		}
		yofs += (screen->pitch / 4);
	}
}

static Uint32 blend_avg(Uint32 source, Uint32 target)
{
	Uint32 sourcer = (source >>  0) & 0xff;
	Uint32 sourceg = (source >>  8) & 0xff;
	Uint32 sourceb = (source >> 16) & 0xff;
	
	Uint32 targetr = (target >>   0) & 0xff;
	Uint32 targetg = (target >>   8) & 0xff;
	Uint32 targetb = (target >>  16) & 0xff;

	targetr = (sourcer + targetr) / 2;
	targetg = (sourceg + targetg) / 2;
	targetb = (sourceb + targetb) / 2;

	return  (targetr <<  0) |
		(targetg <<  8) |
		(targetb << 16);
}

static Uint32 blend_mul(Uint32 source, Uint32 target)
{
	Uint32 sourcer = (source >>  0) & 0xff;
	Uint32 sourceg = (source >>  8) & 0xff;
	Uint32 sourceb = (source >> 16) & 0xff;
	
	Uint32 targetr = (target >>   0) & 0xff;
	Uint32 targetg = (target >>   8) & 0xff;
	Uint32 targetb = (target >>  16) & 0xff;

	targetr = (sourcer * targetr) >> 8;
	targetg = (sourceg * targetg) >> 8;
	targetb = (sourceb * targetb) >> 8;

	return  (targetr <<  0) |
		(targetg <<  8) |
		(targetb << 16);
}

static Uint32 blend_add(Uint32 source, Uint32 target)
{
	Uint32 sourcer = (source >>  0) & 0xff;
	Uint32 sourceg = (source >>  8) & 0xff;
	Uint32 sourceb = (source >> 16) & 0xff;
	
	Uint32 targetr = (target >>   0) & 0xff;
	Uint32 targetg = (target >>   8) & 0xff;
	Uint32 targetb = (target >>  16) & 0xff;

	targetr += sourcer;
	targetg += sourceg;
	targetb += sourceb;

	if (targetr > 0xff) targetr = 0xff;
	if (targetg > 0xff) targetg = 0xff;
	if (targetb > 0xff) targetb = 0xff;

	return  (targetr <<  0) |
		(targetg <<  8) |
		(targetb << 16);
}

static Uint32 blend_mod(Uint32 source, Uint32 target)
{
	Uint32 sourcer = (source >>  0) & 0xff;
	Uint32 sourceg = (source >>  8) & 0xff;
	Uint32 sourceb = (source >> 16) & 0xff;
	
	Uint32 targetr = (target >>   0) & 0xff;
	Uint32 targetg = (target >>   8) & 0xff;
	Uint32 targetb = (target >>  16) & 0xff;

	targetr += sourcer;
	targetg += sourceg;
	targetb += sourceb;
	
	targetr = (targetr % 0xff);
	targetg = (targetg % 0xff);
	targetb = (targetb % 0xff);


	return  (targetr <<  0) |
		(targetg <<  8) |
		(targetb << 16);
}


void scaleblit() 
{	
	int i, j, yofs;
	yofs = 0;
	for (i=0; i<480; i++) {
		for (j=0; j<640; j++) {

			int c = (int)((i * 0.95f) + 12) * 640
				+ (int)((j * 0.95f) + 16);

			Uint32 *pixels = ((Uint32 *)screen->pixels);
			pixels[yofs + j] = blend_avg(pixels[yofs + j],
				tempbuf[c]);
		}

		yofs += (screen->pitch / 4);
	}
}

void init()
{
	tempbuf = malloc(sizeof(Uint32) * (640 * 480));
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
	Uint32 tick = SDL_GetTicks();


	int i, d;
	for (int i=0; i<480; i++) {
		d = tick + i * 4;
		drawsprite((int)(320+sin(d * 0.0034f)*sin(d * 0.0134) * 300),
			(int)(240+sin(d * 0.0033f)*sin(d * 0.0234f) * 220),
			((int)(sin((tick * 0.2f + i) * 0.234897f)
				* 127 + 128) << 16) |
			((int)(sin((tick * 0.2f + i) * 0.123489f)
				* 127 + 128) <<  8) |
			((int)(sin((tick * 0.2f + i) * 0.312348f)
				* 127 + 128) <<  0));
	}

	for (i=0; i<480; i++) {
		memcpy(tempbuf + i * 640,
			((Uint32 *)screen->pixels) + i * (screen->pitch / 4),
			640 * 4);
	}

	scaleblit();

	/* unlock if needed */
	if (SDL_MUSTLOCK(screen)) {
		SDL_UnlockSurface(screen);
	}

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

	init();

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
