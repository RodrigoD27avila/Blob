#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <luaconf.h>

int main()
{
	lua_State *L = lua_open();
	lua_close(L);
	return 0;
}

