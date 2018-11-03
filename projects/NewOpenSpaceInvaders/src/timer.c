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

#include "timer.h"

void timer_Start(struct Timer *timer)
{
	/* if timer is running return */
	if (timer->started) {
		return;
	}
 
	/* initialize status */
	timer->start_ticks  = SDL_GetTicks();
	timer->count_ticks       = 0;
	timer->started           = SDL_TRUE;
	timer->paused            = SDL_FALSE;
}

void timer_Stop(struct Timer *timer)
{
	/* stop timer */
	timer->started      = SDL_FALSE;
	timer->paused       = SDL_FALSE;
}

Uint32 timer_GetTicks(struct Timer *timer)
{
	/* if the timer is started */
	if (timer->started && !timer->paused) {
		Uint32 currticks      = SDL_GetTicks();
		timer->count_ticks   += (currticks - timer->start_ticks);
		timer->start_ticks    = currticks; 
	}

	return timer->count_ticks;
}

void timer_Pause(struct Timer *timer)
{
	if (timer->started) {
		timer->paused = SDL_TRUE;
	}
}

void timer_Unpause(struct Timer *timer)
{
	if (timer->paused) {
		timer->paused      = SDL_FALSE;
		timer->start_ticks = SDL_GetTicks();
	}
}
