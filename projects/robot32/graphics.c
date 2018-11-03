#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphics.h"
#include "invaders.h"
#include "window.h"

void graphics_Present()
{
	SDL_RenderPresent(window_GetMainRenderer());
}

void graphics_EraseScreen()
{
	SDL_RenderClear(window_GetMainRenderer());
}

void graphics_Copy(struct GameObject *obj, struct Sprite *sprites)
{
	if (!obj->visible) {
		return;
	}

	SDL_Rect src  = {0, 0, obj->w, obj->h};
	SDL_Rect dest = {(int)obj->pos.x, (int)obj->pos.y, obj->w, obj->h};
	SDL_RenderCopy(window_GetMainRenderer(), sprites[obj->sprite_index].texture, &src, &dest);
}

SDL_Rect graphics_SpriteToRect(struct Sprite *sprite)
{
	SDL_Rect rect = {0, 0, sprite->w, sprite->h};
	return rect;
}
