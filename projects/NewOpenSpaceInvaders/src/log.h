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


#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <stdio.h>
#include <stdarg.h>

#ifdef NDEBUG
#	define debug(M, ...)
#else
#	define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n"\
		, __FILE__, __LINE__, ## __VA_ARGS__);
#endif

void log_Init(FILE *error, FILE *warning, FILE *info);
void log_Quit();

void log_Error(const char *msg, ...);
void log_Warning(const char *msg, ...);
void log_Info(const char *msg, ...);

#endif /* LOG_H_INCLUDED */
