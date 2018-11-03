#ifndef TEXTURE_H_INCUDED
#define TEXTURE_H_INCUDED

#include <SDL.h>

struct Texture {
	Uint32 id;
	Uint32 w, h;	
};

void texture_Init();
void texture_Quit();

void texture_LoadFromPixel32(struct Texture *texture, Uint32 *pixels,
		Uint32 width, Uint32 height);

void texture_LoadFromFile(struct Texture *texture, const char *filename);

void texture_Free(struct Texture *texture);

#endif /* TEXTURE_H_INCUDED */
