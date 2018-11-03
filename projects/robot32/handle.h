#ifndef HANDLE_H_INCLUDED
#define HANDLE_H_INCLUDED

#include <SDL.h>

#define EVENTKEYBOARD (1 << 0)
#define EVENTMOUSE    (1 << 1)
#define EVENTJOYSTICK (1 << 2)
#define EVENTTOUCH    (1 << 3)
#define EVENTSYSTEM   (1 << 4)
#define EVENTUSER     (1 << 5)

typedef void (*HandleFunction)(void *);

struct Handle {
	SDL_bool key_enabled;
	SDL_bool mouse_enabled;
	SDL_bool joystick_enabled;
	SDL_bool touch_enabled;
	SDL_bool system_enabled;
	SDL_bool user_enabled;

	HandleFunction key;
	HandleFunction mouse;
	HandleFunction joystick;
	HandleFunction touch;
	HandleFunction system;
	HandleFunction user;
};

void     handle_Init();
void     handle_Quit();

void     handle_PollEvent(struct Handle *handle);
void     handle_WaitEvent(struct Handle *handle);
void     handle_EnableEvents(struct Handle *handle, Uint32 mask);

SDL_Joystick *handle_GetJoystick(Uint16 index);

#endif /* HANDLE_H_INCLUDED */
