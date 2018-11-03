#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "core.h"
#include "types.h"

namespace Classes {

class Sprite {
public:
	void     createEmpty            (u32 width, u32 height, u32 bpp=32);
	void     createFromImage        (const char *image);
	u32      getWidth               ();
	u32      getHeight              ();
	u32      getBpp                 ();
	void     *getPixels             ();

	Sprite();
	~Sprite();
private:
	u32  width;
	u32  height;
	u32  bpp;
	void *pixels;
};

} // end namespace Classes


#endif // SPRITE_H_INCLUDED
