#include <memory>
#include <SDL.h>

int main()
{

	SDL_Init(SDL_INIT_EVERYTHING);

	std::shared_ptr<SDL_Window> mywindow(SDL_CreateWindow("haha", 0, 0, 640, 480, SDL_WINDOW_SHOWN), [=] (SDL_Window *window) {
		SDL_DestroyWindow(window);
	});
	
	SDL_Delay(10000);
}
