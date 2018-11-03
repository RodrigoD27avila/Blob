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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "event.h"
#include "timer.h"

void event_Start(struct Event *event)
{
	if (!event->started) {
		event->started     = SDL_TRUE;
		event->start_ticks = timer_GetTicks(event->timer);
		event->last_ticks  = event->start_ticks;
		event->count_ticks = 0;
	}
}

void event_RegisterCallback(struct Event *event,struct Timer *timer,
	void (*callback)(void *), void *data, Uint32 ticks)
{

	event->callback = callback;
	event->data     = data;
	event->ticks    = ticks;
	event->timer    = timer;
}

void event_Callback(struct Event *event)
{
	if (event->started) {
		Uint32 currticks    = timer_GetTicks(event->timer);
		event->count_ticks += currticks - event->last_ticks;
		event->last_ticks   = currticks;

		while (event->count_ticks >= event->ticks) {
			event->callback(event->data);
			event->count_ticks -= event->ticks;
		} 
	}
}

Uint32  event_GetTicksFromStart(struct Event *event)
{
	return timer_GetTicks(event->timer) - event->start_ticks;
}
