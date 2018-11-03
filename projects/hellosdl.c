#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#define SCREEN_FPS 60

int main()
{
	// display mode
	SDL_DisplayMode target, closest;

	// window
	SDL_Window *mywindow = NULL;

	// rederer
	SDL_Renderer *renderer = NULL;

	// surface
	SDL_Surface *surface   = NULL;

	// teture
	SDL_Texture *texture = NULL;

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	target.w      = 640;
	target.h      = 480;
	target.format = 0;
	target.refresh_rate = 0;
	target.driverdata   = 0;

	// check display mode
	if (SDL_GetClosestDisplayMode(0, &target, &closest) < 0) {
		fprintf(stderr, "Unable to get display mode: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}


	// create window
	mywindow = SDL_CreateWindow("SDL2 WINDOW", 0, 0,
		closest.w, closest.h, SDL_WINDOW_SHOWN);

	// check window 
	if (mywindow == NULL) {
		fprintf(stderr, "Unable to create SDL Window.\n");
		exit(EXIT_FAILURE);
	}

	// create renderer
	renderer = SDL_CreateRenderer(mywindow, -1, 0);
	
	// check renderer
	if (renderer == NULL) {
		fprintf(stderr, "Unable to create a renderer to Window.\n");
		exit(EXIT_FAILURE);
		
	}

	// load

	SDL_Rect myrect = {100, 100, 200, 200};

	surface = SDL_LoadBMP("teste.bmp");
	if (surface == NULL) {
		fprintf(stderr, "Unable to load image %s:\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// start color key
	SDL_PixelFormat *pixel = surface->format;
	SDL_Surface *newsurface = SDL_CreateRGBSurface(surface->flags,
		 surface->w, surface->h, pixel->BitsPerPixel, pixel->Rmask,
		 pixel->Gmask, pixel->Bmask, pixel->Amask);

	if (newsurface == NULL) {
		fprintf(stderr, "Unable to create new surface %s:\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	Uint32 i, len = surface->w * surface->h;

	SDL_LockSurface(newsurface);
	for (i=0; i<len; i++) {
		Uint32 *thepixels = (Uint32 *)surface->pixels;	
		Uint32 *newpixels = (Uint32 *)newsurface->pixels;

		Uint32 color = thepixels[i];
		if (color == SDL_MapRGB(surface->format, 255, 0, 255))
			continue;

		newpixels[i] = color;
	}
	SDL_UnlockSurface(newsurface);

	// end colorkey

	SDL_Rect src  = {0, 0, surface->w, surface->h};
	SDL_Rect dest = {10, 10, surface->w, surface->h};

	texture = SDL_CreateTextureFromSurface(renderer, newsurface);
	SDL_FreeSurface(newsurface);
	SDL_FreeSurface(surface);

	SDL_Event event;
	SDL_bool  quit = SDL_FALSE;

	Uint32 start, end;

	while (!quit) {

		start = SDL_GetTicks();

		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			}
			
		}
	
		// draw here
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &myrect);

	
		SDL_RenderCopy(renderer, texture, &src, &dest);

		// draw
		SDL_RenderPresent(renderer);


		end = SDL_GetTicks();

		if ((1000.0 / SCREEN_FPS) > (end - start)) {
			Uint32 delaytime = (1000.0 / SCREEN_FPS) - (end - start);
			SDL_Delay(delaytime);
		}

	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(mywindow);
	SDL_Quit();

	return 0;
}
