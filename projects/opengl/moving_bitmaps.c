#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

#define NUM 50

SDL_Surface *surface;

SDL_bool twinkle = SDL_FALSE;

typedef struct
{
    int r, g, b;
    GLfloat dist;
    GLfloat angle;

} star;

star stars[NUM];

GLfloat zoom = -15.0;
GLfloat tilt =  90.0;

GLuint loop;
GLuint texture[1];

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

SDL_bool load_gl_textures()
{
    SDL_bool status = SDL_FALSE;
    SDL_Surface *textureimage[1];

    if ((textureimage[0] = SDL_LoadBMP("data/star.bmp")))
    {
        status = SDL_TRUE;

        glGenTextures(1, &texture[0]);
        
        /*Load in texture*/
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, textureimage[0]->w,
                textureimage[0]->h, 0, GL_BGR,
                GL_UNSIGNED_BYTE, textureimage[0]->pixels);
    }

    if (textureimage[0])
        SDL_FreeSurface(textureimage[0]);

    return status;
    
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
	    case SDLK_t:
            twinkle = !twinkle;
	        break;
	    case SDLK_UP:
            tilt -= 0.5;
	        break;
	    case SDLK_DOWN:
            tilt += 0.5;
	        break;
	    case SDLK_PAGEUP:
            zoom -= 0.2;
	        break;
	    case SDLK_PAGEDOWN:
            zoom += 0.2;
	        break;
	    default:
	        break;
	}
}

SDL_bool init()
{

    if (!load_gl_textures())
        return SDL_FALSE;

    glEnable(GL_TEXTURE_2D);

    /* Enable smooth shading */
    glShadeModel(GL_SMOOTH);

    /* Set the background black */
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    /* Depth buffer setup */
    glClearDepth(1.0f);

    /* Really Nice Perspective Calculations */
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glEnable(GL_BLEND);

    for (loop=0; loop < NUM; loop++)
    {
        stars[loop].angle = 0.0;
        stars[loop].dist = ((float)loop / NUM) * 5.0;

        stars[loop].r = rand() % 256;
        stars[loop].g = rand() % 256;
        stars[loop].b = rand() % 256;
    }

    return SDL_TRUE;
}

#define CINDEX (NUM - loop) -1
/* Here goes our drawing code */
SDL_bool draw()
{
    static int spin = 0;

    /* These are to calculate our fps */
    static GLint t0     = 0;
    static GLint frames = 0;

    /* Clear The Screen And The Depth Buffer */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glLoadIdentity();

    /*DRAW HERE*/

    for (loop=0; loop < NUM; loop++)
    {
        glLoadIdentity();
        glTranslatef(0.0, 0.0, zoom);

        glRotatef(tilt, 1.0, 0.0, 0.0);
        glRotatef(stars[loop].angle, 0.0, 1.0, 0.0);

        glTranslatef(stars[loop].dist, 0.0, 0.0);

        glRotatef(-stars[loop].angle, 0.0, 1.0, 0.0);
        glRotatef(-tilt, 1.0, 0.0, 0.0);

        if (twinkle)
        {
            glColor4ub(stars[CINDEX].r, stars[CINDEX].g,
                    stars[CINDEX].b, 255);

            glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
                glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0, 0.0);
                glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, 0.0);
                glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, 0.0);
            glEnd();
        }

        glRotatef(spin, 0.0, 0.0, 1.0);
        glColor4ub(stars[loop].r, stars[loop].g, stars[loop].b, 255);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,-1.0, 0.0);
            glTexCoord2f(1.0, 0.0); glVertex3f( 1.0,-1.0, 0.0);
            glTexCoord2f(1.0, 1.0); glVertex3f( 1.0, 1.0, 0.0);
            glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
        glEnd();

        spin += 0.01;
        stars[loop].angle += (float)loop / NUM;
        stars[loop].dist  -= 0.01;

       if (stars[loop].dist < 0.0)
       {
            stars[loop].dist += 5.0f;
            stars[loop].r = rand() % 256;
            stars[loop].g = rand() % 256;
            stars[loop].b = rand() % 256;
        }

    }

    printf ("spin = %i\n", spin);
    printf ("tilt = %F\n", tilt);
    printf ("zoom = %F\n", zoom);

    for (loop=0; loop < NUM; loop++)
    {
        printf(">> %f, %f\n", stars[loop].dist, stars[loop].angle);
    }
     

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
