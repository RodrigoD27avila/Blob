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

#include "invaders.h"
#include "memory.h"
#include "settings.h"
#include "timer.h"
#include "window.h"
#include "handle.h"
#include "game.h"

static SDL_bool   quit;

static SDL_Thread *thread_handle;
static SDL_Thread *thread_update;
static SDL_Thread *thread_render;

static int        ThreadHandle(void *data);
static int        ThreadUpdate(void *data);
static int        ThreadRender(void *data);

static CallbackFunc handle;
static CallbackFunc render;
static CallbackFunc update;

static void InvadersSetLoopFunctions();

static void Flip();
static void WaitThreads();

static void Cleanup();
static void Delay(Uint32 start);

void invaders_Init()
{
	/* initialize SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* initialize settings */
	settings_InitDefault();

	/* intialize joystick */
	handle_InitializeJoystick();

	/* initialize window */
	window_Init();

	/* initialize game*/
	game_Init();
	
	/* set game funtions to loop*/;
	InvadersSetLoopFunctions();
}

void invaders_Quit()
{
	/* quit */
	quit = SDL_TRUE;

	/* quit game*/
	game_Quit();

	/* quit invaders */
	Cleanup();
	printf("Good Bye!\n");
	exit(EXIT_SUCCESS);
}

void invaders_Exit()
{
	/* quit invaders */
	Cleanup();
	exit(EXIT_FAILURE);
}

void invaders_StartMainLoop()
{
	/* simple main loop */
	while(!quit) {

		Uint32 start = SDL_GetTicks();

		handle();
		update();
		render();
		
		Flip();

		Delay(start);
	}
}

static int ThreadHandle(void *data)
{
	/* loop handle */
	while (!quit) { handle(); }
	return 0;
}

static int ThreadUpdate(void *data)
{
	/* loop update */
	while (!quit) { update(); }
	return 0;
}

static int ThreadRender(void *data)
{
	/* loop render */
	while (!quit) {

		Uint32 start = SDL_GetTicks();
		render();

		Flip();
		Delay(start);
	}

	return 0;
}

void invaders_StartMainLoopThreads()
{
	/* create threads */
	thread_handle = SDL_CreateThread(ThreadHandle, NULL);
	thread_update = SDL_CreateThread(ThreadUpdate, NULL);
	thread_render = SDL_CreateThread(ThreadRender, NULL);

	/* wait threads */
	WaitThreads();
}

void invaders_SetHandleFunction(CallbackFunc func)
{ handle = func; }

void invaders_SetRenderFunction(CallbackFunc func)
{ render = func; }

void invaders_SetUpdateFunction(CallbackFunc func)
{ update = func; }

static void Flip()
{
	/* flip the screen */
	if (SDL_Flip(window_GetScreen()) < 0) {
		fprintf(stderr, "Unable to flip screen. %s",
			SDL_GetError());
		invaders_Exit();
	}
}

static void WaitThreads()
{
	/* wait for threads */
	if (thread_handle) {
		SDL_WaitThread(thread_handle, NULL);
	}
	if (thread_update) {
		SDL_WaitThread(thread_update, NULL);
	}
	if (thread_render) {
		SDL_WaitThread(thread_render, NULL);
	}
}

static void Cleanup()
{
	/* wait */
	WaitThreads();

	/* quit SDL */
	SDL_Quit();
}

static void Delay(Uint32 start)
{
	/* get ticks */
	Uint32 ticks     = SDL_GetTicks() - start;
	Uint32 deltatime = 1000.0f / settings_GetScreenFPS();

	/* delay */
	if (ticks < deltatime) {
		SDL_Delay(deltatime - ticks);
	}
}

static void InvadersSetLoopFunctions()
{
	/* loop Game */
	invaders_SetHandleFunction(game_Handle);
	invaders_SetUpdateFunction(game_Update);
	invaders_SetRenderFunction(game_Render);
}

void invaders_DefaultSystemHandle(void *event)
{
	/* Quit */
	SDL_Event *levent = (SDL_Event *)event;
	if (levent->type == SDL_QUIT) {
		invaders_Quit();
	}
}
