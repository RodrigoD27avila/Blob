#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "window.h"
#include "settings.h"

static SDL_Window   *main_window;
static SDL_Renderer *main_renderer;

void window_Init()
{

	main_window = SDL_CreateWindow( settings_GetWindowTitle(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			settings_GetScreenWidth(), settings_GetScreenHeight(),
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	/* check if screen is NULL */
	if (main_window == NULL) {
		fprintf(stderr, "Unable to create window: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
	/* check if screen is NULL */
	if (main_renderer == NULL) {
		fprintf(stderr, "Unable to create renderer: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void window_Quit()
{
	SDL_DestroyRenderer(main_renderer);
	SDL_DestroyWindow(main_window);
}

Uint16 window_GetWidth()
{ return settings_GetScreenWidth(); }

Uint16 window_GetHeight()
{ return settings_GetScreenHeight(); }

SDL_Window *window_GetMainWindow()
{ return main_window; }

SDL_Renderer *window_GetMainRenderer()
{ return main_renderer; }
