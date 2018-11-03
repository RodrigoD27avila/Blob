#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "event.h"
#include "timer.h"

void event_Start(struct Event *event)
{
	if (!event->started) {
		event->started     = SDL_TRUE;
		event->start_ticks = timer_GetTicks(event->timer);
		event->last_ticks  = event->start_ticks;
		event->count_ticks = 0;
	}
}

void event_RegisterCallback(struct Event *event,struct Timer *timer,
	void (*callback)(void *), void *data, Uint32 ticks)
{

	event->callback = callback;
	event->data     = data;
	event->ticks    = ticks;
	event->timer    = timer;
}

void event_Callback(struct Event *event)
{
	if (event->started) {
		Uint32 currticks    = timer_GetTicks(event->timer);
		event->count_ticks += currticks - event->last_ticks;
		event->last_ticks   = currticks;

		while (event->count_ticks >= event->ticks) {
			event->callback(event->data);
			event->count_ticks -= event->ticks;
		} 
	}
}

Uint32  event_GetTicksFromStart(struct Event *event)
{
	return timer_GetTicks(event->timer) - event->start_ticks;
}
