#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL.h>

struct Timer {
	SDL_bool started;
	SDL_bool paused;

	Uint32   start_ticks;
	Uint32   count_ticks;
};

void     timer_Start(struct Timer *timer);
void     timer_Stop(struct Timer *timer);
void     timer_Pause(struct Timer *timer);
void     timer_Unpause(struct Timer *timer);

Uint32   timer_GetTicks(struct Timer *timer);

#endif /* TIMER_H_INCLUDED */
