#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <SDL.h>

#define MAX_ALIENS 32

struct GameObject;
struct Sprite;

void level_Level1(struct GameObject *objs, struct Sprite *sprites);

#endif /* LEVEL_H_INCLUDED */
