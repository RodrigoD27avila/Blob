#include "settings.h"

namespace Classes {

static s32 screen_width;
static s32 screen_height;
static s32 screen_bpp;

///
/// return screen width in pixels
///
EXTERNC u32 settings_GetScreenWidth()
{ return screen_width; }

///
/// return screen height in pixels
///
EXTERNC u32 settings_GetScreenHeight()
{ return screen_height; }

///
/// return screen bpp in bits
///
EXTERNC u32 settings_GetScreenBpp()
{ return screen_bpp; }

} // end namespace classes
