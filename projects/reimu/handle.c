/*
 * OpenSpaceInvaders - Another space invaders remake in C + SDL.
 * Copyright (C) 2012  Rodrigo D'avila <r0dra42@gmail.com>
 * Copyright (C) 2013  Rodrigo D'avila <r0dra42@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "handle.h"

#define MAX_JOYSTICKS 1
#define DEFAULT_SENSITIVITY 32767

static SDL_Joystick *joyticks[MAX_JOYSTICKS];
static Uint32       sensitivity = DEFAULT_SENSITIVITY;

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

	/* handle system events */
	if (handle->system_enabled) {
		handle->system(event);
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
	handle->key_enabled      = mask & EVENT_KEYBOARD;
	handle->mouse_enabled    = mask & EVENT_MOUSE;
	handle->joystick_enabled = mask & EVENT_JOYSTICK;
	handle->system_enabled   = mask & EVENT_SYSTEM;
	handle->user_enabled     = mask & EVENT_USER;
}

void handle_InitializeJoystick()
{
	int numjoysticks = SDL_NumJoysticks();

	/* number of joysticks = 0*/
	if (numjoysticks <= 0) {
		return;
	}

	/* enable joystick event */
        SDL_JoystickEventState(SDL_ENABLE);

	int i;
        for (i=0; i < numjoysticks && i < MAX_JOYSTICKS; i++) {
		/* get joystick */
                SDL_Joystick *joy = SDL_JoystickOpen(i);
		joyticks[i] = joy;
		
                printf("Joystick %i: %s\n", i, SDL_JoystickName(i));

		/* print some additional information */
		printf("\tNumber of axes      : %i\n",
			SDL_JoystickNumAxes(joy));
		printf("\tNumber of trackballs: %i\n",
			SDL_JoystickNumBalls(joy));
		printf("\tNumber of hats      : %i\n",
			SDL_JoystickNumHats(joy));
		printf("\tNumber of buttons   : %i\n",
			SDL_JoystickNumButtons(joy));
		printf("\n");
		
        }
}

Uint32 handle_GetSensitivity()
{ return sensitivity; }

void handle_SetSensitivity(Uint32 sen)
{ sensitivity = sen; }

SDL_Joystick *handle_GetJoystick(Uint16 index)
{ return joyticks[index]; }
