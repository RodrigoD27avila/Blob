#ifndef PANTSU_VIDEO_WINDOW_H
#define PANTSU_VIDEO_WINDOW_H

#include "pantsu/Core.h"

namespace pantsu {

struct Window_Private;

class DLL_PUBLIC Window {
public:
	/// get window width
	u16 width();

	/// get window height
	u16 height();

	/// get window bits per pixel
	u16 bpp();

	/// get window flags
	u16 flags()

	/// get window title
	const char *title();

	/// returns if the window is fullscreen
	bool isFullscreen();

	/// set width and height
	void setGeometry(u16 width, u16 height);

	/// set window fullscreen
	void setFullscreen(bool fullscreen);

	/// set title
	void setTitle(const char *title);

	/// set bits per pixel
	void setBpp(u16 bpp);

	/// set window flags
	void setFlags(u32 flags);

	/// show/update window
	void show();

	/// creates an instance of the Window class
	Window(u16 width, u16 height, u32 bpp, u32 flags=0);

	/// delete this instance of the Window class
	~Window();

private:
	Window_Private *priv;
};

} // end namespace pantsu

#endif // PANTSU_VIDEO_WINDOW_H
