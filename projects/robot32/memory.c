#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"

void *memory_Alloc(size_t bytes)
{
	void *pointer = SDL_malloc(bytes);
	if (pointer == NULL) {
		fprintf(stderr, "Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	SDL_memset(pointer, 0, bytes);

	return pointer;
}


void memory_Free(void *obj)
{
	SDL_free(obj);
}
