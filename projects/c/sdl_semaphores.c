#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>
#include <SDL_thread.h>

#define MAX_BUFFER 60

char buffer[MAX_BUFFER];

SDL_Thread *threadA = NULL;
SDL_Thread *threadB = NULL;

SDL_sem *bufferLock = NULL;


void dobuffer(char *msg)
{
	SDL_SemWait(bufferLock);
	memset(buffer, 0, MAX_BUFFER);
	strncpy(buffer, msg, MAX_BUFFER-1);
	printf("%s\n", buffer);
	SDL_SemPost(bufferLock);
}

int pprint(void *data)
{
	dobuffer(data);
	return 0;
}

int main()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		exit(EXIT_FAILURE);
	}

	bufferLock = SDL_CreateSemaphore(1);
	threadA = SDL_CreateThread(pprint, "Hello 01");
	threadB = SDL_CreateThread(pprint, "Hello 02");

	SDL_WaitThread(threadB, NULL);
	SDL_WaitThread(threadA, NULL);

	printf("Bye!!\n");
	SDL_DestroySemaphore(bufferLock);
	SDL_Quit();

	return 0;
}
