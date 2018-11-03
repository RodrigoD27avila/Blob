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


#ifndef SCRIPT_H_INCLUDED
#define SCRIPT_H_INCLUDED

#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

void      script_Init();
void      script_Quit();

lua_State *script_GetState();

void      script_Load(const char *sname);
int       script_GetGlobalInt(const char *name, int *number);
int       script_GetGlobalBool(const char *name, int *boolean);
int       script_GetGlobalString(const char *name, char **string);

#endif /* SCRIPT_H_INCLUDED */
