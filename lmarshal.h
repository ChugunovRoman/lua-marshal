#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#define LUA_MARSHALLIBNAME "marshal"

int luaopen_marshal(lua_State *L);
