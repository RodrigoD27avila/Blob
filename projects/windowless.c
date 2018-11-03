#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
 
typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
typedef Bool (*glXMakeContextCurrentARBProc)(Display*, GLXDrawable, GLXDrawable, GLXContext);
static glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
static glXMakeContextCurrentARBProc glXMakeContextCurrentARB = 0;
 
int main(int argc, const char* argv[]){
        static int visual_attribs[] = {
                None
        };
        int context_attribs[] = {
                GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
                GLX_CONTEXT_MINOR_VERSION_ARB, 0,
                None
        };
 
        Display* dpy = XOpenDisplay(0);
        int fbcount = 0;
        GLXFBConfig* fbc = NULL;
        GLXContext ctx;
        GLXPbuffer pbuf;
 
        /* open display */
        if ( ! (dpy = XOpenDisplay(0)) ){
                fprintf(stderr, "Failed to open display\n");
                exit(1);
        }
 
        /* get framebuffer configs, any is usable (might want to add proper attribs) */
        if ( !(fbc = glXChooseFBConfig(dpy, DefaultScreen(dpy), visual_attribs, &fbcount) ) ){
                fprintf(stderr, "Failed to get FBConfig\n");
                exit(1);
        }
 
        /* get the required extensions */
        glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB( (const GLubyte *) "glXCreateContextAttribsARB");
        glXMakeContextCurrentARB = (glXMakeContextCurrentARBProc)glXGetProcAddressARB( (const GLubyte *) "glXMakeContextCurrent");
        if ( !(glXCreateContextAttribsARB && glXMakeContextCurrentARB) ){
                fprintf(stderr, "missing support for GLX_ARB_create_context\n");
                XFree(fbc);
                exit(1);
        }
 
        /* create a context using glXCreateContextAttribsARB */
        if ( !( ctx = glXCreateContextAttribsARB(dpy, fbc[0], 0, True, context_attribs)) ){
                fprintf(stderr, "Failed to create opengl context\n");
                XFree(fbc);
                exit(1);
        }
 
        /* create temporary pbuffer */
        int pbuffer_attribs[] = {
                GLX_PBUFFER_WIDTH, 800,
                GLX_PBUFFER_HEIGHT, 600,
                None
        };
        pbuf = glXCreatePbuffer(dpy, fbc[0], pbuffer_attribs);
 
        XFree(fbc);
        XSync(dpy, False);
 
        /* try to make it the current context */
        if ( !glXMakeContextCurrent(dpy, pbuf, pbuf, ctx) ){
                /* some drivers does not support context without default framebuffer, so fallback on
                 * using the default window.
                 */
                if ( !glXMakeContextCurrent(dpy, DefaultRootWindow(dpy), DefaultRootWindow(dpy), ctx) ){
                        fprintf(stderr, "failed to make current\n");
                        exit(1);
                }
        }
 
        /* try it out */
        printf("vendor: %s\n", (const char*)glGetString(GL_VENDOR));
 
        return 0;
}
