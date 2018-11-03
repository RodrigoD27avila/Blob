#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_thread.h>

int print_foo(void *data)
{
	printf("print foo %i", (int)data);
	return 0;
}


int main()
{
//	if (SDL_Init(SDL_INIT_THREAD) < 0) {
//		return -1;
//	}

	SDL_Thread *thread1 = NULL;
	thread1 = SDL_CreateThread(print_foo, (void *) 1);

	SDL_KillThread(thread1);
//	SDL_Quit();
	return 0;
}
