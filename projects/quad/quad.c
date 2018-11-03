#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <EGL/egl.h>

#include "quadint.h"

#define QUAD_EGL_CONFIGS_SIZE 256
static EGLConfig _eglConfigs[QUAD_EGL_CONFIGS_SIZE];

const EGLint _configAttributes[] = {
	EGL_COLOR_BUFFER_TYPE, EGL_RGB_BUFFER,
	EGL_BUFFER_SIZE      , 32,
	EGL_RED_SIZE         , 8,
	EGL_GREEN_SIZE       , 8,
	EGL_BLUE_SIZE        , 8,
	EGL_ALPHA_SIZE       , 8,
	EGL_DEPTH_SIZE       , 24,
	EGL_STENCIL_SIZE     , 8,
	EGL_SURFACE_TYPE     , EGL_WINDOW_BIT,
	EGL_NONE,
};

void _QFatal(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	fprintf(stderr, "QUAD: ");
	vfprintf(stderr, format, args);

	va_end(args);
	putc('\n', stderr);
	exit(EXIT_FAILURE);
}

void QEGLInit(const char *display_name)
{
	_Q_ptr = &_Q_state_global;

	_QNativeDisplayInit(display_name);
	_Q_ptr->display.egl = eglGetDisplay(_Q_ptr->display.native);

	if (!eglInitialize(_Q_ptr->display.egl,
		&_Q_ptr->display.major, &_Q_ptr->display.minor)) {
		eglTerminate(_Q_ptr->display.egl);
		_QFatal("failed to initialize egl.");
	}

}

Quad_Window *QCreateWindow(const char *title, int x, int y, int w, int h)
{

	Quad_Window *window = _QAlloc(sizeof(Quad_Window));
	
	/* create a native window */
	_QNativeWindowInit(window, title, x, y, w, h);
	
	EGLint numconfigs = 0;
	EGLBoolean config_ok = eglChooseConfig(_Q_ptr->display.egl,
		_configAttributes, _eglConfigs, QUAD_EGL_CONFIGS_SIZE, &numconfigs);

	if (!config_ok) {
		_QFatal("faile to choose egl configuration.");
	}

	if (numconfigs == 0) {
		_QFatal("failed to find suitable egl configuration.");
	}

	/* save egl configuration */
	window->config = _eglConfigs[0];

	EGLContext context = eglCreateContext(_Q_ptr->display.egl,
		window->config, EGL_NO_CONTEXT, NULL);

	if (context == EGL_NO_CONTEXT) {
		_QFatal("failed to create gl context.");
	}

	/* save gl context */
	window->context = context;

	return window;
}

void *_QAlloc(size_t bytes)
{
	void *ptr = calloc(1, bytes);
	if (ptr == NULL) {
		_QFatal("unable to allocate memory.");
	}
	return ptr;
}

void _QFree(void *ptr)
{
	free(ptr);
}
