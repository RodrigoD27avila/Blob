#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static void stack_dump(lua_State *L)
{
	int i;
	int top = lua_gettop(L);
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
}

int main()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	lua_pushnil(L);
	lua_pushstring(L, "Rodrigo D'avila");
	stack_dump(L);
	lua_close(L);
	return 0;
}
