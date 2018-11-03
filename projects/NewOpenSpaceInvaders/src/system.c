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
#include <stdarg.h>

#include "log.h"
#include "system.h"
#include "script.h"
#include "load.h"
#include "settings.h"
#include "window.h"
#include "opengl.h"
#include "texture.h"

static const char *settings_file;

static void Quit();
static void OpenLogFiles();

void system_Init(const char *fname)
{
	/* initialize SDL */
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		system_Exit();
	}

	/* set settings file name*/
	settings_file = fname;

	/* initialize script */
	script_Init();

	/* open settings */
	if (load_OpenSettings() < 0) {
		/* set default settings */
		settings_InitDefault();
	}
	else {
		/* load settings from settings file */
		settings_InitFromScript();
	}
	
	/* open log */
	OpenLogFiles();

	/* initialize window */
	window_Init();

	/* initialize opengl */
	opengl_Init();

	/* initialize texture */
	texture_Init();
}

void system_Quit()
{
	Quit();
	exit(EXIT_SUCCESS);
}

void system_Loop()
{
	log_Error("Teste Error %s", "AAARARARA");
	log_Warning("Teste Warning %s", "AAARARARA");
	log_Info("Teste Info %s", "AAARARARA");
	SDL_Delay(10000);
	system_Quit();
}

void system_Exit()
{
	Quit();
	exit(EXIT_FAILURE);
}

const char *system_SettingsFileName()
{ return settings_file; }

static void Quit()
{
	/* quit texture */
	texture_Quit();

	/* quit script */
	script_Quit();

	/* free string settings */
	settings_FreeStrings();
	
	/* quit SDL */
	SDL_Quit();
	
	/* quit log*/
	log_Quit();
}

static void OpenLogFiles()
{
	FILE *error, *warning, *info;

	/* try open error log file*/
	if ((error = fopen(settings_GetErrorLogFile(), "w+")) < 0) {
		error = NULL;
	}

	/* try open warning log file*/
	if ((warning = fopen(settings_GetWarningLogFile(), "w+")) < 0) {
		warning = NULL;
	}

	/* try open info log file*/
	if ((info = fopen(settings_GetInfoLogFile(), "w+")) < 0) {
		info = NULL;
	}
	
	/* initialize log */
	log_Init(error, warning, info);
}
