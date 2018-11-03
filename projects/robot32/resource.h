#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

#include <SDL.h>

#include "vector.h"

typedef vector_t SpriteVector;

struct Sprite;

void resource_Init();
void resource_Quit();

SpriteVector *resource_GetSprites();

#endif /* RESOURCE_H_INCLUDED */
