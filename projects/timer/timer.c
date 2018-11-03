#include <time.h>

#include "timer.h"

static void GetTicks()
{
	/*ticks in milliseconds */
	unsigned int ticks;
	struct timespec currenttime;

	/* get time */
	clock_gettime(CLOCK_MONOTONIC, &currenttime);

	/* calculate milliseconds */
	ticks = currenttime.tv_sec * 1000
		+ currenttime.tv_usec / 1000000;

	return ticks;
}

void timer_Start(struct Timer *timer)
{
	/* if timer is running return */
	if (timer->started) {
		return;
	}
 
	/* initialize status */
	timer->last_start_ticks  = GetTicks();
	timer->last_get_ticks    = timer->last_start_ticks;

	timer->count_ticks       = 0;
	timer->count_start_ticks = 0;
	timer->started           = 1;
	timer->paused            = 1;
}

void timer_Stop(struct Timer *timer)
{
	/* stop timer */
	timer->started      = 0;
	timer->paused       = 0;
}

Uint32 timer_GetTicks(struct Timer *timer)
{
	/* if the timer is started */
	if (timer->started && !timer->paused) {
		Uint32 currticks      = GetTicks();
		timer->count_ticks   += (currticks - timer->last_get_ticks); 
		timer->last_get_ticks = currticks;
	}

	return timer->count_ticks;
}

Uint32 timer_GetTicksFromStart(struct Timer *timer)
{
	if (timer->started && !timer->paused) {
		Uint32 currticks = GetTicks();
		timer->count_start_ticks +=
			(currticks - timer->last_start_ticks);

		timer->last_start_ticks = currticks;
	}

	return timer->count_start_ticks;
}

void timer_Pause(struct Timer *timer)
{
	if (timer->started) {
		timer->paused = 1;
	}
}

void timer_Unpause(struct Timer *timer)
{
	if (timer->paused) {
		timer->paused           = 0;
		timer->last_start_ticks = GetTicks();
		timer->last_get_ticks   = timer->last_start_ticks; 
	}
}

void timer_Callback(struct Timer *timer)
{
	/* if the timer is paused */
	if (timer->paused) return;

	while (timer_GetTicks(timer) > timer->callback_ticks) {

		/* adjust ticks */
		timer->count_ticks -= timer->callback_ticks;

		/* call callback function */
		timer->callback();
	}
}

void timer_RegisterCallback(struct Timer *timer,
		void (*callback)(void), Uint32 callback_ticks)
{
	timer->callback       = callback;
	timer->callback_ticks = callback_ticks;
}

void timer_UpdateCallbackTicks(struct Timer *timer, Uint32 ticks)
{
	/* update callback ticks*/
	timer->callback_ticks = ticks;
}
