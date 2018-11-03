/*
 * NewOpenSpaceInvaders
 * Another space invaders remake in C + SDL + OpenGL + Lua
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
