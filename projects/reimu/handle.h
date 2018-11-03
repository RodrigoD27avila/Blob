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

#ifndef HANDLE_H_INCLUDED
#define HANDLE_H_INCLUDED

#include <SDL.h>

#define EVENT_KEYBOARD (1 << 0)
#define EVENT_MOUSE    (1 << 1)
#define EVENT_JOYSTICK (1 << 2)
#define EVENT_SYSTEM   (1 << 4)
#define EVENT_USER     (1 << 5)

typedef void (*HandleFunction)(void *);

struct Handle {
	SDL_bool key_enabled;
	SDL_bool mouse_enabled;
	SDL_bool joystick_enabled;
	SDL_bool system_enabled;
	SDL_bool user_enabled;

	HandleFunction key;
	HandleFunction mouse;
	HandleFunction joystick;
	HandleFunction system;
	HandleFunction user;
};

void     handle_PollEvent(struct Handle *handle);
void     handle_WaitEvent(struct Handle *handle);
void     handle_EnableEvents(struct Handle *handle, Uint32 mask);

Uint32   handle_GetSensitivity();
void     handle_SetSensitivity(Uint32 sen);

SDL_Joystick *handle_GetJoystick(Uint16 index);
void         handle_InitializeJoystick();

#endif /* HANDLE_H_INCLUDED */
