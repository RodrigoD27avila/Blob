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

	ilConvertImage(IL_BGRA, IL_UNSIGNED_BYTE);

	return id;
}

int main()
{
	// window
	SDL_Surface *mywindow = NULL;

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

	// create window
	mywindow = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	// check window 
	if (mywindow == NULL) {
		fprintf(stderr, "Unable to create SDL Window.\n");
		exit(EXIT_FAILURE);
	}

	// load
	ILuint id  = il_LoadImage("ball.png");

	// create texture
	ilBindImage(id);
	Uint32 width  = (Uint32)ilGetInteger(IL_IMAGE_WIDTH);
	Uint32 height = (Uint32)ilGetInteger(IL_IMAGE_HEIGHT);

	SDL_PixelFormat *fmt = mywindow->format;
	SDL_Surface *dummy = SDL_CreateRGBSurface(mywindow->flags,
		width, height, fmt->BitsPerPixel,
		fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);

	if (dummy == NULL) {
		fprintf(stderr, "Unable to create RGB Surface.\n");
		exit(EXIT_FAILURE);
	}

	Uint32 *src  = (Uint32 *)ilGetData();
	Uint32 *dest = (Uint32 *)dummy->pixels;

	// copy pixels
	Uint32 i;
	for (i=0; i< (width * height); i++) {
		if (src[i] == 0x00ffffff) {
			dest[i] = SDL_MapRGB(dummy->format, 255, 0, 255);
			continue;
		}

		dest[i] = src[i];
	}

	SDL_SetColorKey(dummy, SDL_SRCCOLORKEY,
		SDL_MapRGB(dummy->format, 255, 0, 255));

	ilDeleteImages(1, &id);
	
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
		SDL_FillRect(mywindow, &mywindow->clip_rect,
			SDL_MapRGB(mywindow->format, 0, 0, 0));

		SDL_Rect offset = {100, 100, 0, 0};
		if (SDL_BlitSurface(dummy, NULL, mywindow, &offset) < 0) {
			fprintf(stderr, "Could not blit surface: %s\n",
				 SDL_GetError());
			exit(EXIT_FAILURE);
		}

		// update

		SDL_Flip(mywindow);


		end = SDL_GetTicks();

		if ((1000.0 / SCREEN_FPS) > (end - start)) {
			Uint32 delaytime = (1000.0 / SCREEN_FPS) - (end - start);
			SDL_Delay(delaytime);
		}

	}

	SDL_FreeSurface(dummy);
	SDL_FreeSurface(mywindow);
	SDL_Quit();

	return 0;
}
