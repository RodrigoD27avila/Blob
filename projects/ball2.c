#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <IL/il.h>

#define SCREEN_FPS 60

ILuint il_LoadImage(const char *image)
{
	ILuint id = 0;
	ilGenImages(1, &id);
	ilBindImage(id);
	ILboolean success = ilLoadImage(image);
	if (!success) {
		fprintf(stderr, "Unable to load %s\n", image);
		exit(EXIT_FAILURE);
	}

	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

	return id;
}

int main()
{
	// display mode
	SDL_DisplayMode target, closest;

	// window
	SDL_Window *mywindow = NULL;

	// rederer
	SDL_Renderer *renderer = NULL;

	// teture
	SDL_Texture *texture = NULL;

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}
 
	// initialize devil
	ilInit();
	ilClearColor(255, 255, 255, 000);
	ILenum error = ilGetError();
	if (error != IL_NO_ERROR) {
		fprintf(stderr, "Unable to start DevIL.\n");
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
	ILuint id  = il_LoadImage("ball.png");

	// create texture
	ilBindImage(id);
	Uint32 width  = (Uint32)ilGetInteger(IL_IMAGE_WIDTH);
	Uint32 height = (Uint32)ilGetInteger(IL_IMAGE_HEIGHT);

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING, width, height); 

	SDL_UpdateTexture(texture, NULL, ilGetData(), 512);
	ilDeleteImages(1, &id);
	
	SDL_Rect src  = {0, 0, width, height};
	SDL_Rect dest = {10, 10, width, height};

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
