#include "sprite.h"

BEGIN_NAMESPACE_CLASSES

Sprite::Sprite()
	: width(0), height(0), bpp(0), pixels(0)
{}

Sprite::~Sprite()
{
	delete[] ((char *)pixels);
}

// -----------------------------------------------------------------------

void Sprite::createEmpty(u32 width, u32 height, u32 bpp)
{
	this->width  = width;
	this->height = height;
	this->bpp    = bpp;
	this->pixels = (void *)new char[width * height * (bpp / 8)];
	
}

void Sprite::createFromImage(const char *image)
{
}

// -----------------------------------------------------------------------

u32 Sprite::getWidth()
{ return width; }

u32 Sprite::getHeight()
{ return height; }

u32 Sprite::getBpp()
{ return bpp; }

void *Sprite::getPixels()
{ return pixels; }

END_NAMESPACE_CLASSES
