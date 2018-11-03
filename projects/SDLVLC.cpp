#include <SDL.h>
#include <SDL_mutex.h>

#include <vlc.h>

#define WIDTH  640
#define HEIGHT 480

#define VIDEO_WIDTH  320
#define VIDEO_HEIGHT 240

struct Context {
	SDL_Renderer *renderer;
	SDL_Texture  *texture;
	SDL_Mutex    *mutex;
	int          n;
};
