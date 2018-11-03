#include "pantsu/Private/Window_Private.h"

Window_Private()
{
	width      = 0;
	height     = 0;
	fullscreen = false;
}

Window_Private::~Window_Private()
{
	delete title;
}

