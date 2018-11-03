#include "sdlplusplus.h"
using namespace SDL;

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	auto window   = CreateWindow("lalala", 0, 0, 100, 100, SDL_WINDOW_SHOWN);
	auto renderer = CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED);
	SDL_Delay(1000);
}
