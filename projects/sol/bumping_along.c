#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "SDL/SDL.h"

// Screen surface
SDL_Surface *gScreen;


// Screen pitch
#define PITCH (gScreen->pitch / 4)
// Screen width
#define WIDTH 480
// Screen height
#define HEIGHT 320
// Definition of PI
#define PI 3.1415926535897932384626433832795f


// Physics iterations per second
#define PHYSICSFPS 100

// Last iteration's tick value
int gLastTick;


void init()
{
}


void render()
{	 
	// Ask SDL for the time in milliseconds
	int tick = SDL_GetTicks();

	if (tick <= gLastTick) 
	{
		SDL_Delay(1);
		return;
	}

	while (gLastTick < tick)
	{
		// 'physics' here

		gLastTick += 1000 / PHYSICSFPS;
	}

	// Lock surface if needed
	if (SDL_MUSTLOCK(gScreen))
		if (SDL_LockSurface(gScreen) < 0) 
			return;

	// rendering here

	// Unlock if needed
	if (SDL_MUSTLOCK(gScreen)) 
		SDL_UnlockSurface(gScreen);

	// Tell SDL to update the whole gScreen
	SDL_UpdateRect(gScreen, 0, 0, WIDTH, HEIGHT);	
}


// Entry point
int main(int argc, char *argv[])
{
	// Initialize SDL's subsystems
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(1);
	}

	// Register SDL_Quit to be called at exit; makes sure things are
	// cleaned up when we quit.
	atexit(SDL_Quit);
	 
	// Attempt to create a WIDTHxHEIGHT window with 32bit pixels.
	gScreen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE);
	
	init();

	// If we fail, return error.
	if (gScreen == NULL) 
	{
		fprintf(stderr, "Unable to set up video: %s\n", SDL_GetError());
		exit(1);
	}

	// Main loop: loop forever.
	while (1)
	{
		// Render stuff
		render();

		// Poll for events, and handle the ones we care about.
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_KEYUP:
					
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					// If escape is pressed, return (and thus, quit)
					return 0;
				}
				break;
			case SDL_QUIT:
				return(0);
			}
		}
	}
	return 0;
}
