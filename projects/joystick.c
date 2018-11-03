#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#define MAX_JOYSTICKS 4

int main()
{
	static SDL_Joystick *joyticks[MAX_JOYSTICKS];

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	static int i;
	for (i=0; i < SDL_NumJoysticks() && i < MAX_JOYSTICKS; i++) {
		printf("Joystick %i: %s\n", i, SDL_JoystickName(i));

		SDL_JoystickEventState(SDL_ENABLE);
		joyticks[i] = SDL_JoystickOpen(i);
	}

	static SDL_Event event;
	static SDL_bool  quit;

	while (!quit) {
	
		if (SDL_PollEvent(&event)) {

			switch(event.type) {
			case SDL_JOYBUTTONDOWN:
				break;
			case SDL_JOYBUTTONUP
				break;
			case SDL_JOYAXISMOTION:
				break;
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			}
		}
	}

	SDL_Quit();
	return 0;
} 
