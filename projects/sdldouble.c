#include <SDL.h>

int main()
{
	SDL_Surface *s1;
	SDL_Surface *s2;

	SDL_Init(SDL_INIT_VIDEO);
	s1 = SDL_SetVideoMode(100, 100, 16, SDL_SWSURFACE);
	s2 = SDL_SetVideoMode(100, 100, 16, SDL_SWSURFACE);
	SDL_Delay(5000);
	
	return 0;
}
