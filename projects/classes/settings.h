#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "core.h"
#include "types.h"

BEGIN_NAMESPACE_CLASSES

// screen width
EXTERNC u32 settings_GetScreenWidth();

// screen height
EXTERNC u32 settings_GetScreenHeight();

// screen bpp
EXTERNC u32 settings_GetScreenBpp();

END_NAMESPACE_CLASSES

#endif // SETTINGS_H_INCLUDED
