#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "timer.h"

void timer_Start(struct Timer *timer)
{
	/* if timer is running return */
	if (timer->started) {
		return;
	}

	/* initialize status */
	timer->start_ticks  = SDL_GetTicks();
	timer->count_ticks       = 0;
	timer->started           = SDL_TRUE;
	timer->paused            = SDL_FALSE;
}

void timer_Stop(struct Timer *timer)
{
	/* stop timer */
	timer->started      = SDL_FALSE;
	timer->paused       = SDL_FALSE;
}

Uint32 timer_GetTicks(struct Timer *timer)
{
	/* if the timer is started */
	if (timer->started && !timer->paused) {
		Uint32 currticks      = SDL_GetTicks();
		timer->count_ticks   += (currticks - timer->start_ticks);
		timer->start_ticks    = currticks;
	}

	return timer->count_ticks;
}

void timer_Pause(struct Timer *timer)
{
	if (timer->started) {
		timer->paused = SDL_TRUE;
	}
}

void timer_Unpause(struct Timer *timer)
{
	if (timer->paused) {
		timer->paused      = SDL_FALSE;
		timer->start_ticks = SDL_GetTicks();
	}
}
