#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "action.h"
#include "timer.h"

void action_Start(struct Action *action)
{
	if (!action->started) {
		action->started     = SDL_TRUE;
		action->start_ticks = timer_GetTicks(action->timer);
		action->last_ticks  = action->start_ticks;
		action->count_ticks = 0;
	}
}

void action_Stop(struct Action *action)
{
	action->started = SDL_FALSE;
}

void action_RegisterCallback(struct Action *action,struct Timer *timer,
	void (*callback)(void *), void *data, Uint32 ticks)
{

	action->callback = callback;
	action->data     = data;
	action->ticks    = ticks;
	action->timer    = timer;
}

void action_Callback(struct Action *action)
{
	if (action->started) {
		Uint32 currticks    = timer_GetTicks(action->timer);
		action->count_ticks += currticks - action->last_ticks;
		action->last_ticks   = currticks;

		while (action->count_ticks >= action->ticks) {
			action->callback(action->data);
			action->count_ticks -= action->ticks;
		} 
	}
}

Uint32  action_GetTicksFromStart(struct Action *action)
{
	return timer_GetTicks(action->timer) - action->start_ticks;
}
