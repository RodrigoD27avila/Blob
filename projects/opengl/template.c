#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

SDL_Surface *surface;

void quit(int num)
{
    SDL_Quit();
    exit(num);
}

SDL_bool resize_window(int width, int height)
{
    GLfloat ratio;
    
    if ( height == 0 )
	    height = 1;

    ratio = ( GLfloat )width / ( GLfloat )height;

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLint )width, ( GLint )height );

    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );

    return SDL_TRUE;
}

/* function to handle key press events */
void handle_key_press(SDL_keysym *keysym)
{
    switch (keysym->sym)
	{
	    case SDLK_ESCAPE:
	        quit(EXIT_SUCCESS);
	        break;
	    case SDLK_F1:
	        SDL_WM_ToggleFullScreen(surface);
	        break;
	    default:
	        break;
	}
}

SDL_bool init()
{

    /* Enable smooth shading */
    glShadeModel(GL_SMOOTH);

    /* Set the background black */
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    /* Depth buffer setup */
    glClearDepth(1.0f);

    /* Enables Depth Testing */
    glEnable(GL_DEPTH_TEST);

    /* The Type Of Depth Test To Do */
    glDepthFunc(GL_LEQUAL);

    /* Really Nice Perspective Calculations */
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    return SDL_TRUE;
}

/* Here goes our drawing code */
SDL_bool draw()
{
    /* These are to calculate our fps */
    static GLint t0     = 0;
    static GLint frames = 0;

    /* Clear The Screen And The Depth Buffer */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    /*DRAW HERE*/

    /* Draw it to the screen */
    SDL_GL_SwapBuffers();

    /* Gather our frames per second */
    frames++;
    {
	    Uint32 t = SDL_GetTicks();
	    if (t - t0 >= 5000) {
	        float seconds = (t - t0) / 1000.0;
	        float fps = frames / seconds;
	        printf("%d frames in %f seconds = %f FPS\n", frames, seconds, fps);
	        t0 = t;
	        frames = 0;
	}
    }

    return SDL_TRUE;
}

int main( int argc, char **argv )
{
    /* Flags to pass to SDL_SetVideoMode */
    int video_flags;
    /* main loop variable */
    SDL_bool done = SDL_FALSE;
    /* used to collect events */
    SDL_Event event;
    /* this holds some info about our display */
    const SDL_VideoInfo *video_info;
    /* whether or not the window is active */
    SDL_bool is_active = SDL_TRUE;

    /* initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
	    fprintf(stderr, "Video initialization failed: %s\n",
		     SDL_GetError());
        quit(EXIT_FAILURE);
	}

    /* Fetch the video info */
    video_info = SDL_GetVideoInfo();

    if (!video_info)
	{
	    fprintf(stderr, "Video query failed: %s\n",
		     SDL_GetError());
	    quit(EXIT_FAILURE);
	}

    /* the flags to pass to SDL_SetVideoMode */
    video_flags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    video_flags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    video_flags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    video_flags |= SDL_RESIZABLE;       /* Enable window resizing */

    /* This checks to see if surfaces can be stored in memory */
    if (video_info->hw_available )
	    video_flags |= SDL_HWSURFACE;
    else
	    video_flags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    if (video_info->blit_hw)
	    video_flags |= SDL_HWACCEL;

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    /* get a SDL surface */
    surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
				video_flags);

    /* Verify there is a surface */
    if (!surface)
	{
	    fprintf(stderr, "Video mode set failed: %s\n", SDL_GetError());
	    quit(EXIT_FAILURE);
	}

    /* initialize OpenGL */
    if (!init())
	{
	    fprintf(stderr, "Could not initialize OpenGL.\n");
	    quit(EXIT_FAILURE);
	}

    /* Resize the initial window */
    resize_window(SCREEN_WIDTH, SCREEN_HEIGHT);

    /* wait for events */
    while (!done)
	{
	    /* handle the events in the queue */

	    while (SDL_PollEvent(&event))
		{
		    switch(event.type)
			{
		    	case SDL_ACTIVEEVENT:
			        /* Something's happend with our focus
			         * If we lost focus or we are iconified, we
			        * shouldn't draw the screen
			        */
			        if (event.active.gain == 0)
				        is_active = SDL_FALSE;
			        else
				        is_active = SDL_TRUE;
			        break;

			    case SDL_VIDEORESIZE:
			        /* handle resize event */
			        surface = SDL_SetVideoMode(event.resize.w,
					    		event.resize.h,	16, video_flags);
			        if (!surface)
				    {
				        fprintf( stderr,
                                "Could not get a surface after resize: %s\n",
                                SDL_GetError());
				        quit(EXIT_FAILURE);
				    }
			        resize_window(event.resize.w, event.resize.h);
			        break;

			    case SDL_KEYDOWN:
			        /* handle key presses */
			        handle_key_press(&event.key.keysym);
			        break;
			    case SDL_QUIT:

			        /* handle quit requests */
			        done = SDL_TRUE;
			    break;

			    default: break;
			}
		}

	    /* draw the scene */
	    if (is_active)
		    draw();
	}

    /* clean ourselves up and exit */
    quit(EXIT_SUCCESS);

    /* Should never get here */
    return 0;
}
