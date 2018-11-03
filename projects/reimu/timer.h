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
