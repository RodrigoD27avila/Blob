#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_opengl.h>

int main(int argc, char **argv)
{
	SDL_Surface *surface = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	surface = SDL_SetVideoMode(800, 600, 32,
		SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);

	if (surface == nullptr) {
		fprintf(stderr, "Unable to set video mode: %s\n",
			SDL_GetError());

		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Opengl", "Opengl");

	SDL_Event event;
	bool      quit  = false;
	Uint32    start = 0;


	while (!quit) {

		start = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				quit = true;
		}


		SDL_GL_SwapBuffers();

		Uint32 current = SDL_GetTicks();
		if ((current - start) < (1000.0 / 60.0)) {
			SDL_Delay((1000.0 / 60.0) - (current - start));
		}
	}
}
