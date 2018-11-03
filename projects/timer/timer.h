#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

struct Timer {
	unsigned int  started;
	unsigned int  paused;

	unsigned int  last_start_ticks;
	unsigned int  count_start_ticks;
	unsigned int  last_get_ticks;
	unsigned int  count_ticks;

	void (*callback)(void);
	unsigned int callback_ticks;
};

void     timer_Start(struct Timer *timer);
void     timer_Stop(struct Timer *timer);
void     timer_Pause(struct Timer *timer);
void     timer_Unpause(struct Timer *timer);
void     timer_Callback(struct Timer *timer);
void     timer_UpdateCallbackTicks(struct Timer *timer, unsigned int ticks);
void     timer_RegisterCallback(struct Timer *timer,
		void (*callback)(void), unsigned int callback_ticks);

unsigned int  timer_GetTicks(struct Timer *timer);
unsigned int  timer_GetTicksFromStart(struct Timer *timer);

#endif /* TIMER_H_INCLUDED */
