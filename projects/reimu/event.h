#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <SDL.h>

struct Event {
	SDL_bool started;

	void (*callback)(void *);
	void *data;

	Uint32 start_ticks;
	Uint32 last_ticks;
	Uint32 count_ticks;
	Uint32 ticks;
	
	struct Timer *timer;
};

void   event_Start(struct Event *event);

void   event_RegisterCallback(struct Event *event,struct Timer *timer,
	void (*callback)(void *), void *data, Uint32 ticks);

void   event_Callback(struct Event *event);

Uint32 event_GetTicksFromStart(struct Event *event);

#endif // EVENT_H_INCLUDED
