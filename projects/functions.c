#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static void error(lua_State *L, const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	lua_close(L);
	exit(EXIT_FAILURE);
}

static void stack_dump(lua_State *L)
{
	int i;
	int top = lua_gettop(L);
	printf("---- Stack dump init --------------\n");
	printf("top stack index is %i\n", top);
	for (i=1; i<= top; i++) {
		int t = lua_type(L, i);
		switch (t) {
		case LUA_TSTRING:
			printf("\'%s\'", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			printf("%g", lua_tonumber(L, i));
			break;
		default:
			printf("%s", lua_typename(L, t));
			break;
		}
		printf("\n");
	}
	printf("---- Stack dump end  --------------\n");
}

static void load(lua_State *L, const char *fname)
{
	if (luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0)) {
		error(L, "cannot run config. file: %s\n",
			lua_tostring(L, -1));
	}
}

static double f(lua_State *L, double x, double y)
{
	double z;
	lua_getglobal(L, "f");
	lua_pushnumber(L, x);
	lua_pushnumber(L, y);

	if (lua_pcall(L, 2, 1, 0) != 0) {
		error(L, "error running function \'f\': %s\n",
			lua_tostring(L, -1));
	}

	if (!lua_isnumber(L, -1)) {
		error(L, "function \'f\' must return a number.");
	}

	z = lua_tonumber(L, -1);
	lua_pop(L, 1);
	return z;
}

static int l_sin(lua_State *L)
{
	double d = luaL_checknumber(L, 1);
	lua_pushnumber(L, sin(d));
	return 1;
}

int main(int argc, char **argv)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	lua_pushcfunction(L, l_sin);
	lua_setglobal(L, "mysin");

	load(L, "functions.lua");
	stack_dump(L);

	double z  = f(L, 12.4f, 56.8f);
	printf("z = %f\n", z);
	
	lua_close(L);
	return 0;
}
