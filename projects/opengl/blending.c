#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

SDL_Surface *surface;

SDL_bool light = SDL_FALSE;
SDL_bool blend = SDL_FALSE;

GLfloat xrot;
GLfloat yrot;
GLfloat xspeed;
GLfloat yspeed;

GLfloat z = -5.0;

GLfloat LightAmbient[]  = {0.5, 0.5, 0.5, 1.0};
GLfloat LightDiffuse[]  = {1.0, 1.0, 1.0, 1.0};
GLfloat LightPosition[] = {0.0, 0.0, 2.0, 1.0};

GLuint filter;
GLuint texture[3];

void quit(int num)
{
    SDL_Quit();
    exit(num);
}

SDL_bool load_gl_textures()
{
    SDL_bool status = SDL_FALSE;
    SDL_Surface *textureimage[1];

    if ((textureimage[0] = SDL_LoadBMP("data/glass.bmp")))
    {
        status = SDL_TRUE;

        glGenTextures(3, &texture[0]);

        /*Texture 1*/
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, textureimage[0]->w,
                textureimage[0]->h, 0, GL_BGR,
                GL_UNSIGNED_BYTE, textureimage[0]->pixels);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                GL_NEAREST); 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                GL_NEAREST);

        /*Texture 2*/
        glBindTexture(GL_TEXTURE_2D, texture[1]);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, textureimage[0]->w,
                textureimage[0]->h, 0, GL_BGR,
                GL_UNSIGNED_BYTE, textureimage[0]->pixels);

        /*Texture 3*/
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                GL_LINEAR_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                GL_LINEAR);

        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureimage[0]->w,
                textureimage[0]->h, GL_BGR,
                GL_UNSIGNED_BYTE, textureimage[0]->pixels);
    }

    if (textureimage[0])
        SDL_FreeSurface(textureimage[0]);

    return status;

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
	    case SDLK_b:
            blend = !blend;
            if (blend)
            {
                glEnable(GL_BLEND);
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                glDisable(GL_BLEND);
                glEnable(GL_DEPTH_TEST);
            }
	        break;
        case SDLK_f:
            filter +=1;
            filter %=3;
            break;
	    case SDLK_l:
            light = !light;
            if (!light)
                glDisable(GL_LIGHTING);
            else
                glEnable(GL_LIGHTING);
	        break;
        case SDLK_PAGEUP:
            z -= 0.02;
            break;
        case SDLK_PAGEDOWN:
            z += 0.02;
            break;
        case SDLK_UP:
            xspeed -= 0.01;
            break;
        case SDLK_DOWN:
            xspeed += 0.01;
            break;
        case SDLK_RIGHT:
            yspeed += 0.01;
            break;
        case SDLK_LEFT:
            yspeed -= 0.01;
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

    /* Enables Depth Testing */
    glEnable(GL_DEPTH_TEST);

    /* The Type Of Depth Test To Do */
    glDepthFunc(GL_LEQUAL);

    /* Really Nice Perspective Calculations */
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);

    glEnable(GL_LIGHT1);

    glColor4f(1.0, 1.0, 1.0, 0.5);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

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
    glTranslatef(0.0, 0.0, z);

    glRotatef(xrot, 1.0, 0.0, 0.0);
    glRotatef(yrot, 0.0, 1.0, 0.0);

    glBindTexture(GL_TEXTURE_2D, texture[filter]);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
        glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);
        glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0,  1.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);
        
        glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
        glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
        glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);

        glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0,  1.0,  1.0);
        glTexCoord2f(1.0, 0.0); glVertex3f( 1.0,  1.0,  1.0);
        glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
        
        glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0);
        glTexCoord2f(0.0, 1.0); glVertex3f( 1.0, -1.0, -1.0);
        glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
        
        glTexCoord2f(1.0, 0.0); glVertex3f( 1.0, -1.0, -1.0);
        glTexCoord2f(1.0, 1.0); glVertex3f( 1.0,  1.0, -1.0);
        glTexCoord2f(0.0, 1.0); glVertex3f( 1.0,  1.0,  1.0);
        glTexCoord2f(0.0, 0.0); glVertex3f( 1.0, -1.0,  1.0);

        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0,  1.0);
        glTexCoord2f(1.0, 1.0); glVertex3f(-1.0,  1.0,  1.0);
        glTexCoord2f(0.0, 1.0); glVertex3f(-1.0,  1.0, -1.0);
    glEnd();


    /* Draw it to the screen */
    SDL_GL_SwapBuffers();

    /* Gather our frames per second */
    frames++;
    {
	    Uint32 t = SDL_GetTicks();
	    if (t - t0 >= 5000)
        {
	        float seconds = (t - t0) / 1000.0;
	        float fps = frames / seconds;
	        printf("%d frames in %f seconds = %f FPS\n", frames, seconds, fps);
	        t0 = t;
	        frames = 0;
	    }
    }
    
    xrot += xspeed;
    yrot += yspeed;

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
