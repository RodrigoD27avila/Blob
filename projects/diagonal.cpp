#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL.h>

struct FRect {
	double x, y, w, h;
};

int main()
{
	SDL_Surface *screen = NULL;
	SDL_Surface *rect   = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);

	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	rect   = SDL_LoadBMP("rect.bmp"); 
		
	FRect pos    = { 0,  0, 0, 0};
	FRect off    = {10, 3, 0, 0};
	FRect versor = {0, 0, 0, 0};
	double mod = sqrt(pow(off.x, 2) + pow(off.y, 2));
	versor.x = off.x / mod;
	versor.y = off.y / mod;
	
	SDL_Event event;
	while (true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				SDL_Quit();
				return 0;
			}
		}
	
		double velx = (versor.x * 2);
		double vely = (versor.y * 2);
		pos.x += velx;
		pos.y += vely;

		SDL_Rect spos = {0};
		spos.x = static_cast<Uint16>(pos.x);
		spos.y = static_cast<Uint16>(pos.y);

		SDL_FillRect(screen, &screen->clip_rect,
			SDL_MapRGB(screen->format, 0, 0, 0));

		SDL_BlitSurface(rect, &rect->clip_rect, screen, &spos);
		SDL_Flip(screen);

		SDL_Delay(10);
	}

	

	SDL_Quit();
}
