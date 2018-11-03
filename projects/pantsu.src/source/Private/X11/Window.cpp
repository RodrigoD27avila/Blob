#include <X11/X.h>
#include <X11/Xlib.h>

#include "pantsu/Private/X11/Window.h"
#include "pantsu/System/System.h"
#include "pantsu/Log/Logger.h"


namespace pantsu  {
namespace Private {

struct Window_Private {
	Display     *display;
	Window      root;
	Window      self;
	XVisualInfo *visualinfo;
};

s32 Window_Private::initialize()
{
	priv->display = XOpenDisplay(NULL);
	if (dpy == NULL) {
		logger_Error("Cannot connect to X Server.");
		system_Exit();
	}
}

Window_Private::create()
{
	priv->display = 
}

} // end namespace Private
} // end namespace pantsu
