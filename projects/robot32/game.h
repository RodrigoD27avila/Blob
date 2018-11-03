#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>

#include "vector.h"
#include "timer.h"
#include "scene.h"
#include "action.h"

typedef void (*StateHandleFunc) (Uint32);
typedef void (*ActionHandleFunc)(void *data);

struct GameObject {
	vec2     pos;
	Uint16   w, h;
	Uint32   sprite_index;
	SDL_bool visible;

	Uint32          curr_state;
	StateHandleFunc state_handle;

	Uint32 actions_count;
	struct Action **actions;
	ActionHandleFunc action_handle;

	Uint32 type;
};

struct Scene *game_GetScene();
int           game_GetSpriteIndex(int type);

#endif /* GAME_H_INCLUDED */
