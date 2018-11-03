#include <SDL.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *image = SDL_LoadBMP("teste.bmp");
	SDL_FreeSurface(image);
	SDL_Quit();
	return 0;
}
