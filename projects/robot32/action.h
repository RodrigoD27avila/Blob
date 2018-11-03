#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include <SDL.h>

struct Action {
	SDL_bool started;

	void (*callback)(void *);
	void *data;

	Uint32 start_ticks;
	Uint32 last_ticks;
	Uint32 count_ticks;
	Uint32 ticks;

	struct Timer *timer;

	struct Action *next;
};

void   action_Start(struct Action *action);
void   action_Stop(struct Action *action);

void   action_RegisterCallback(struct Action *action,struct Timer *timer,
	void (*callback)(void *), void *data, Uint32 ticks);

void   action_Callback(struct Action *action);

Uint32 action_GetTicksFromStart(struct Action *action);

#endif // ACTION_H_INCLUDED
