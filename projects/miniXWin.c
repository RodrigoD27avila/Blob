#define NAME "miniXWin"
#define SUMMARY "XWindows and XRender simple window and drawing test"
#define VERSION "0.2"
#define COPYRIGHT "(C)2005-2009 HeGaSoft"
#define ADDRESS "http://www.mathematik.uni-marburg.de/~gasi/"
/******************************************************************************
 * compile e.g. with :
 *
   gcc -Wall miniXWin.c -DTIMEOUT -DXRENDER -I/usr/include/freetype2 \
       -o miniXWin -L/usr/X11R6/lib -lX11 -lXrender -lXft
 *
 * extracting only X-Windows example:
   sed '/^#ifdef XRENDER/,/^#endif.*XRENDER/d' miniXWin.c
 *
 * -DXRENDER : without - only standard XWindows is used
 * -DTIMEOUT : enables close of window after some seconds (for testing)
 *
 * the creation of xrender Picture / PictFormat seems to be incorrect!
 *   it only works with Xft and some special and different PictStandardRGB24
 *   and PictStandardA8 ...
 * drawing redraw() needs some simplifications!
 *
 * shurely many more XWindows and XRenderer misuses!
 *
 * changelog:
 * 2009-04-24 0.2: using select to catch timeout signal correctly(?)
	 	within xevent loop
******************************************************************************/

#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#ifdef XRENDER
#include <X11/StringDefs.h>
#include <X11/IntrinsicP.h>
#include <X11/Xmu/Drawing.h>
#include <X11/Xaw/SimpleP.h>
#include <X11/extensions/Xrender.h>
#include <X11/Xft/Xft.h>
#endif /* XRENDER */

#include <math.h>
#include <stdlib.h>

#ifdef TIMEOUT
#include <signal.h>
#include <unistd.h>
#endif /* TIMEOUT */

const int width = 100;
const int height = 100;
int prec = 2;

/* xwindows variables */
Display *xdisplay = 0;
Drawable xwindow = 0;
GC	xgc = 0;
#ifdef XRENDER
XRenderPictFormat *xpictformat = 0;
Picture	xpicture = 0;
#endif /* XRENDER */

int debug = 1;
int more = 1; // for xevent loop

#ifdef XRENDER
static XPointDouble p1[] = {
	 {  0,   0},
	 { 25,   0},
	 { 56,  41},
	 {  9, 100},
	 {  0, 100},
	 { 39,  51},
	};
static XPointDouble p2[] = {
	 {100,   0},
	 { 91,   0},
	 { 44,  59},
	 { 75, 100},
	 {100, 100},
	 { 61,  49}
	};
#endif /* XRENDER */

void redraw() {
	if( debug>2 )
		fprintf(stderr,"redrawing\n");
	XClearWindow(xdisplay,xwindow);
	XDrawLine(xdisplay,xwindow,xgc,0,height,width,0);
	XDrawRectangle(xdisplay,xwindow,xgc,10,10,40,10);
	XDrawString(xdisplay,xwindow,xgc,10,20,"Test",4);
#ifdef XRENDER
	XRenderColor blue = { red:0,green:0,blue:0xffff,alpha:0x4fff };

	XRenderFillRectangle( xdisplay,PictOpOver,xpicture,&blue,10,80,60,10);

	XftFont *xftfont= XftFontOpen(xdisplay,XDefaultScreen(xdisplay),
		XFT_FAMILY,  XftTypeString,   "times",
		XFT_SIZE,  XftTypeDouble,       24.0,
		NULL);
	XftDraw *xftdraw = XftDrawCreate(xdisplay,xwindow,
			DefaultVisual (xdisplay,DefaultScreen(xdisplay)),
			xpictformat->colormap);
	XftColor xftblue;
	XftColorAllocValue (xdisplay,
			DefaultVisual (xdisplay,DefaultScreen(xdisplay)),
			xpictformat->colormap,
			&blue, &xftblue );
	XftDrawString8(xftdraw,&xftblue,xftfont,10,60,(FcChar8*)"Test",4);

	XRenderColor black = { red:0,green:0,blue:0,alpha:0x3fff };
	XftColor xftblack;
	XftColorAllocValue (xdisplay,
			DefaultVisual (xdisplay,DefaultScreen(xdisplay)),
			xpictformat->colormap,
			&black, &xftblack );
	XRenderCompositeDoublePoly( xdisplay,PictOpOver,
			XftDrawSrcPicture (xftdraw, &xftblack),
			xpicture,
			XRenderFindStandardFormat (xdisplay,PictStandardA8),
			//xpictformat,
			0,0,0,0,p1,6,0);
	XRenderCompositeDoublePoly( xdisplay,PictOpOver,
			XftDrawSrcPicture (xftdraw, &xftblack),
			xpicture,
			XRenderFindStandardFormat (xdisplay,PictStandardA8),
			//xpictformat,
			0,0,0,0,p2,6,0);
#endif /*XRENDER */
}

#ifdef TIMEOUT
void finish( int dummy ) {
	more = 0;
}
#endif /* TIMEOUT */

int main( int argc, char **argv ) {
	int argn = 1;
#ifdef TIMEOUT
	int timeout = 0;
#endif /* TIMEOUT */
	while( argn<argc && argv[argn][0] == '-' ) {
		const char *p = argv[argn++];
		switch( p[1] ) {
#ifdef TIMEOUT
		case 't':	timeout = atoi(argv[argn++]);
				break;
#endif /* TIMEOUT */
		case 'd':	debug = atoi(argv[argn++]);
				break;
		default:	fprintf(stderr,"unknown option %s\n",p);
				exit(2);
		}
	}
	if( debug )
		fprintf(stderr,NAME " " VERSION "\n " SUMMARY "\n " ADDRESS "\n");
#ifdef TIMEOUT
	if( timeout>0 ) {
		signal(SIGALRM,finish);
		alarm(timeout);
	}
#endif /* TIMEOUT */
	xdisplay = XOpenDisplay(None);
	if( xdisplay==None ) {
		fprintf(stderr,"cannot open display\n");
		return 1;
	}
	xwindow = XCreateSimpleWindow( xdisplay,
		DefaultRootWindow(xdisplay),
		0,0, width, height,
		0,
		BlackPixel(xdisplay,DefaultScreen(xdisplay)),
		WhitePixel(xdisplay,DefaultScreen(xdisplay)) );
	if( xwindow==None ) {
		fprintf(stderr,"cannot open window\n");
		return 1;
	}
#ifdef XRENDER
	if( debug>3 )
		fprintf(stderr,"XRender starts ...\n");
	int event_base;
	int error_base;
	if( ! XRenderQueryExtension(xdisplay, &event_base, &error_base) ) {
		fprintf(stderr,"XRender extension not found\n");
		return 1;
	}
	if( ! XRenderQueryFormats (xdisplay) ) {
		fprintf(stderr,"XRender not Picture Formats found\n");
		return 1;
	}
//	xpictformat = XRenderFindStandardFormat (xdisplay,PictStandardARGB32);
	xpictformat = XRenderFindStandardFormat (xdisplay,PictStandardRGB24);
	if( ! xpictformat ) {
		fprintf(stderr,"XRender cannot select ARGB32 Formats\n");
		return 1;
	}
	xpicture = XRenderCreatePicture(xdisplay,xwindow,xpictformat,0,0);
#endif /* XRENDER */

	xgc = XCreateGC(xdisplay, xwindow, 0, 0);   /* create a graphics context */
	XSetBackground(xdisplay, xgc, WhitePixel(xdisplay,DefaultScreen(xdisplay)));
	XSetForeground(xdisplay, xgc, BlackPixel(xdisplay,DefaultScreen(xdisplay)));

	if( debug>1 )
		fprintf(stderr,"preparation done\n");

	XSelectInput(xdisplay, xwindow, ((1L<<25)-1) );
	XMapWindow(xdisplay,xwindow);

	// starting the event loop
	XEvent xevent;
	// accept window close buttom
	Atom proto = XInternAtom(xdisplay,"WM_PROTOCOLS",True);
	Atom delwin = XInternAtom (xdisplay, "WM_DELETE_WINDOW", False);
	XSetWMProtocols (xdisplay, xwindow, &delwin, 1);
#ifdef TIMEOUT
	int fd = ConnectionNumber(xdisplay);
	fd_set fds;
#endif
	if( debug>0 )
		fprintf(stderr,"starting event loop\n");
	while(more) {
#ifdef TIMEOUT
		while( XPending(xdisplay)) {
#endif
			XNextEvent(xdisplay, &xevent);
			switch( xevent.type ) {
			case Expose:
				if(xevent.xexpose.count == 0) {
					redraw();
				}
				break;
			case DestroyNotify:
				if( debug>1 )
					fprintf(stderr,"destroying!\n");
				more = 0;
				break;
			case ClientMessage:
				if( xevent.xclient.message_type == proto
					&& (Atom)xevent.xclient.data.l[0] == delwin ) {
					more = False;
					if( debug>3 )
						fprintf(stderr,"- WM_DELETE_WINDOW\n");
				}
				break;
			default:
				if( debug>3 )
					fprintf(stderr,"- missed x11 event : %d\n",xevent.type);
			}
#ifdef TIMEOUT
		}
		FD_ZERO(&fds);
		FD_SET(fd, &fds); // add display connection file descriptor
		if (select(fd + 1, &fds, 0, 0, 0) == 0) {
			// waiting to next event or interrupt
		}
#endif
	}
	if( debug>0 )
		fprintf(stderr,"leaving event loop\n");
	return 0;
}