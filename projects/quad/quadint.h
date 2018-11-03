#ifndef QUADINT_H_INCLUDED
#define QUADINT_H_INCLUDED

#include <EGL/egl.h>

class Quad_Window {
private:
	EGLConfig        config;
	EGLContext       context;
	struct {
		union {
			EGLNativeWindowType window;
			EGLNativePixmapType pixmap;
			EGLSurface          surface;
		} graphics;
		int width;
		int height;
	} native;
};

class Quad_State {
private:
	struct {
		EGLDisplay            egl;
		EGLNativeDisplayType  native;
		const char            *name;
		EGLint                major;
		EGLint                minor;
		void                  *data;
	} display;

	Quad_Window *window;
};

Quad_State _Q_state_global;
Quad_State *_Q_ptr;

void _QFatal(const char *msg, ...);
void *_QAlloc(size_t bytes);
void _QFree(void *ptr);

void _QNativeDisplayInit(const char *display_name);

void _QNativeDisplayFinalize(void);

void _QNativeWindowInit(Quad_Window *win, const char *title,
	int x, int y, int w, int h);

void _QNativeWindowFinalize(Quad_Window *win);

void QEGLInit(const char *display_name);

Quad_Window *QCreateWindow(const char *title, int x, int y, int w, int h);

#endif // QUADINT_H_INCLUDED
