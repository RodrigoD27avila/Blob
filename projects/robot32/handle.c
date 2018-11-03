#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "handle.h"
#include "window.h"

#define MAX_JOYSTICKS 1
static SDL_Joystick *joyticks[MAX_JOYSTICKS];

static void OpenJoysticks();
static void CloseJoysticks();
static void DefaultSystemHandle(void *event);

void handle_Init()
{
	/*open joysticks */
	OpenJoysticks();
}

void handle_Quit()
{
	/* close joysticks */
	CloseJoysticks();
}


static void CallEventHandle(struct Handle *handle, void *event)
{
	/* handle kyboard events */
	if (handle->key_enabled) {
		handle->key(event);
	}

	/* handle mouse events */
	if (handle->mouse_enabled) {
		handle->mouse(event);
	}

	/* handle joystick events */
	if (handle->joystick_enabled) {
		handle->joystick(event);
	}

	/* handle touch events */
	if (handle->touch_enabled) {
		handle->touch(event);
	}

	/* handle system events */
	if (handle->system_enabled) {
		handle->system(event);
	} else {
		DefaultSystemHandle(event);
	}

	/* handle user events */
	if (handle->user_enabled) {
		handle->user(event);
	}
}

void handle_PollEvent(struct Handle *handle)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		CallEventHandle(handle, &event);
	}
}

void handle_WaitEvent(struct Handle *handle)
{
	SDL_Event event;
	while (SDL_WaitEvent(&event)) {
		CallEventHandle(handle, &event);
	}
}

void handle_EnableEvents(struct Handle *handle, Uint32 mask)
{
	handle->key_enabled      = mask & EVENTKEYBOARD;
	handle->mouse_enabled    = mask & EVENTMOUSE;
	handle->joystick_enabled = mask & EVENTJOYSTICK;
	handle->system_enabled   = mask & EVENTSYSTEM;
	handle->user_enabled     = mask & EVENTUSER;
}

SDL_Joystick *handle_GetJoystick(Uint16 index)
{ return joyticks[index]; }

static void OpenJoysticks()
{
	Uint16 num_joysticks = SDL_NumJoysticks();
	if (num_joysticks > 0) {

		// only one joystick at moment
		joyticks[0] = SDL_JoystickOpen(0);
		if (joyticks[0] == NULL) {
			fprintf(stderr, "Unable to open Joystick 0.\n");
			return;
		}

		printf("Opened Joystick 0\n");
		printf("Name: %s\n", SDL_JoystickNameForIndex(0));
		printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joyticks[0]));
		printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joyticks[0]));
		printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joyticks[0]));

	}
}

static void CloseJoysticks()
{
	int i;
	for (i=0; i<MAX_JOYSTICKS; i++) {
		if (SDL_JoystickGetAttached(joyticks[i])) {
			SDL_JoystickClose(joyticks[i]);
		}

		joyticks[i] = NULL;

	}
}

static void DefaultSystemHandle(void *event)
{
	SDL_Event *local_event = (SDL_Event *)event;
	if (local_event->type == SDL_WINDOWEVENT
		&& SDL_GetWindowID(window_GetMainWindow()) == local_event->window.windowID) {
		if (local_event->window.event == SDL_WINDOWEVENT_CLOSE) {
			invaders_Quit();
		}
	}
}
