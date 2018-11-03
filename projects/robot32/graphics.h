#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <SDL.h>

struct GameObject;

struct Sprite {
	Uint32 id;
	Uint16 w, h;
	SDL_Texture *texture;
};

void          graphics_EraseScreen();
void          graphics_Copy(struct GameObject *obj, struct Sprite *sprites);
void          graphics_Present();

SDL_Rect      graphics_SpriteToRect(struct Sprite *sptrite);


#endif /* GRAPHICS_H_INCLUDED */
