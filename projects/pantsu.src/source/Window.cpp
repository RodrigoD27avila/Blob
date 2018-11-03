#include "pantsu/Window.h"
#include "pantsu/Private/Window_Private.h"

namespace pantsu {

Window::Window(u16 width, u16 height, bool fullscreen)
{
	priv = new Window_Private();
	priv->width      = width;
	priv->height     = height;
	priv->fullscreen = fullscreen;
}

Window::~Window()
{
	delete priv;	
}

void Window::show()
{}

void Window::setFullscreen(bool fullscreen)
{
	priv->fullscreen = fullscreen;
}
	
void Window::setGeometry(u16 width, u16 height)
{
	priv->width  = width;
	priv->height = height; 
}

u16 Window::width()
{
	return priv->width;
}

u16 Window::height()
{
	return priv->height;
}

} // end namespace pantsu
