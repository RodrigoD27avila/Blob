#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#define MAX_SEGMENTS 128

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP    = 32;

const int SNAKE_UP    = 0;
const int SNAKE_DOWN  = 1;
const int SNAKE_LEFT  = 2;
const int SNAKE_RIGHT = 3;

const int level1_max_rect = 10;
static SDL_Rect level1[] = {
    {32, 32, 64, 128 },
    {160, 32, 64, 128},
    {288, 32, 64, 128},
    {416, 32, 64, 128},
    {544, 32, 64, 128},
    {32, 320, 64, 128},
    {160, 320, 64, 128},
    {288, 320, 64, 128},
    {416, 320, 64, 128},
    {544, 320, 64, 128},
};

static int offsets[4] = {-16, 16, -16, 16};

struct Snake {
    int score;
    SDL_bool addseg;
    int   framecount;
    float deltamove;
    int direction;
    SDL_Rect segments[MAX_SEGMENTS];
    int segcount;
};

static SDL_Rect ball;
static TTF_Font    *font;
static Mix_Chunk   *pick;
static Mix_Chunk   *dead;
static SDL_Surface *screen;
static SDL_Surface *myrect;
static SDL_Surface *myball;
static SDL_Surface *text;
static SDL_Color fontcolor;

static SDL_bool quit;
static SDL_bool gameover;
static struct Snake snake;

void init();
void start_game();
void destroy();
void handle();
void update();
void render();

SDL_bool check_collision(SDL_Rect *a, SDL_Rect *b);
void check_collision_itself();
void render_text(int points);
void calc_new_position(SDL_Rect *rectangle);
void apply_surface(SDL_Rect *pos, SDL_Surface *src, SDL_Surface *dest);
void apply_surfaceXY(int x, int y, SDL_Surface *src, SDL_Surface *dest);
void move_snake();
void set_ballpos();
void play_effect(Mix_Chunk *chunk);
void render_rectangles(SDL_Rect *rects, int count);
void check_collisin_rectangles(SDL_Rect *rects, int count);


int main(int argc, char **argv)
{
    init();

    const int TICKS_PER_SECOND = 25;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int FRAME_SKIP = 5;

    Uint32 next_game_tick = SDL_GetTicks();
    int loops;
    float interpolation, previnterpolation=-1;

    while (!quit) {
        loops = 0;

        while (SDL_GetTicks() > next_game_tick
            && loops < FRAME_SKIP) {
            handle();
            update();

            next_game_tick += SKIP_TICKS;
            loops++;
        }

        if (gameover) {
            SDL_Delay(1000);
            start_game();
        }

        interpolation = (float)(SDL_GetTicks() + SKIP_TICKS - next_game_tick)
                    / (float)SKIP_TICKS;


        int ip = (int)(interpolation * 10);
        if ((ip==0 || ip==3 || ip==6 || ip==9) && ip != previnterpolation) {
            previnterpolation = ip;

            render();
            if (SDL_Flip(screen) < 0) {
                fprintf(stderr, "Unble to fip screen: %s",
                    SDL_GetError());
                exit(EXIT_FAILURE);
            }
        }
    }

    destroy();
    return 0;
}

void init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Unable to init SDL: %s\n",
            SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() < 0) {
        fprintf(stderr, "Unable to init TTF: %s\n",
            TTF_GetError());
        exit(EXIT_FAILURE);
    }

    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels  = 2;
    int audio_buffers   = 4096;

    if (Mix_OpenAudio(audio_rate, audio_format,
        audio_channels, audio_buffers) < 0) {
        fprintf(stderr, "Unable to open mixer: %s\n",
            Mix_GetError());
        exit(EXIT_FAILURE);
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,
            SCREEN_BPP, SDL_SWSURFACE);

    if (screen == NULL){
        fprintf(stderr, "Unable to init main screen: %s\n",
            SDL_GetError());
        exit(EXIT_FAILURE);
    }

    font = TTF_OpenFont("font.ttf", 16);
    if (font == NULL) {
        fprintf(stderr, "Unable to init font: %s\n",
            TTF_GetError());
        exit(EXIT_FAILURE);
    }

    pick = Mix_LoadWAV("pick.wav");
    if (pick == NULL) {
        fprintf(stderr, "Unable to load sound effect: %s\n",
            Mix_GetError());
        exit(EXIT_FAILURE);
    }

    dead = Mix_LoadWAV("dead.wav");
    if (dead == NULL) {
        fprintf(stderr, "Unable to load sound effect: %s\n",
            Mix_GetError());
        exit(EXIT_FAILURE);
    }


    fontcolor.r = 0x0;
    fontcolor.g = 0x0;
    fontcolor.b = 0x0;

    myrect = IMG_Load("rect16.png");
    myball = IMG_Load("ball16.png");

    srandom(SDL_GetTicks());
    ball.w = 16;
    ball.h = 16;

    start_game();
}

void start_game()
{
    gameover = SDL_FALSE;
    snake.segcount      = 4;
    memset(&snake.segments[0], 0, MAX_SEGMENTS*sizeof(SDL_Rect));
    snake.segments[3].x = 0;
    snake.segments[2].x = 16;
    snake.segments[1].x = 32;
    snake.segments[0].x = 48;
    snake.segments[3].y = 0;
    snake.segments[2].y = 0;
    snake.segments[1].y = 0;
    snake.segments[0].y = 0;
    snake.segments[3].w = 16;
    snake.segments[2].w = 16;
    snake.segments[1].w = 16;
    snake.segments[0].w = 16;
    snake.segments[3].h = 16;
    snake.segments[2].h = 16;
    snake.segments[1].h = 16;
    snake.segments[0].h = 16;
    snake.deltamove  = 0.4;
    snake.score      = 0;
    snake.framecount = 0;
    snake.direction = SNAKE_RIGHT;

    render_text(snake.score);

    calc_new_position(&ball);
}

void destroy()
{
    Mix_FreeChunk(pick);
    Mix_FreeChunk(dead);
    SDL_FreeSurface(text);
    SDL_FreeSurface(myball);
    SDL_FreeSurface(myrect);
    SDL_FreeSurface(screen);
    TTF_Quit();
    SDL_Quit();
}

void handle()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_UP
                && snake.direction != SNAKE_DOWN) {
                snake.direction = SNAKE_UP;
            }
            else if (event.key.keysym.sym == SDLK_DOWN
                && snake.direction != SNAKE_UP) {
                snake.direction = SNAKE_DOWN;
            }
            else if (event.key.keysym.sym == SDLK_LEFT
                && snake.direction != SNAKE_RIGHT) {
                snake.direction = SNAKE_LEFT;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT
                && snake.direction != SNAKE_LEFT) {
                snake.direction = SNAKE_RIGHT;
            }
        }
        else if (event.type == SDL_QUIT) {
            quit = SDL_TRUE;
            break;
        }
    }
}

void update()
{
    set_ballpos();
    move_snake();
    check_collisin_rectangles(level1, level1_max_rect);
    check_collision_itself();
}

void render()
{
    SDL_FillRect(screen, &screen->clip_rect,
        SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));

    render_rectangles(level1, level1_max_rect);
    apply_surfaceXY(0, 0, text, screen);

    int i;
    for (i=0; i<snake.segcount; i++) {
        apply_surface(&snake.segments[i], myrect, screen);
    }

    apply_surface(&ball, myball, screen);
}

void move_snake()
{
    if (snake.addseg && snake.segcount < MAX_SEGMENTS-1) {
        snake.segcount += 1;
        snake.deltamove += 0.02;
        snake.addseg = SDL_FALSE;
    }

    int j;
    if (snake.framecount++ >= (1 / snake.deltamove)) {
        snake.framecount = 0;

        for (j=snake.segcount; j > 0; j--) {
            snake.segments[j].x = snake.segments[j-1].x;
            snake.segments[j].y = snake.segments[j-1].y;
        }

        if (snake.direction == SNAKE_LEFT || snake.direction == SNAKE_RIGHT) {
            snake.segments[0].x += offsets[snake.direction];
        } else {
            snake.segments[0].y += offsets[snake.direction];
        }

        if (snake.segments[0].x + 16 > SCREEN_WIDTH) {
            snake.segments[0].x = 0;
        } else if (snake.segments[0].x < 0) {
            snake.segments[0].x = SCREEN_WIDTH - 16;
        }

        if (snake.segments[0].y + 16 > SCREEN_HEIGHT) {
            snake.segments[0].y = 0;
        } else if (snake.segments[0].y < 0) {
            snake.segments[0].y = SCREEN_HEIGHT - 16;
        }
    }
}

void apply_surface(SDL_Rect *pos, SDL_Surface *src, SDL_Surface *dest)
{
    if (SDL_BlitSurface(src, &src->clip_rect, dest, pos)) {
        fprintf(stderr, "Unable to blit surface: %s\n",
            SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void apply_surfaceXY(int x, int y, SDL_Surface *src, SDL_Surface *dest)
{
    SDL_Rect offset = {0};
    offset.x = x;
    offset.y = y;
    apply_surface(&offset, src, dest);
}


SDL_bool check_collision(SDL_Rect *a, SDL_Rect *b)
{

    int lA, lB;
    int rA, rB;
    int tA, tB;
    int bA, bB;

    lA = a->x;
    rA = a->x + a->w;
    tA = a->y;
    bA = a->y + a->h;

    lB = b->x;
    rB = b->x + b->w;
    tB = b->y;
    bB = b->y + b->h;

    return !(bA <= tB || tA >= bB || rA <= lB || lA >= rB);
}

void set_ballpos()
{
    if (check_collision(&ball, &snake.segments[0])) {
        calc_new_position(&ball);
        snake.addseg = SDL_TRUE;
        snake.score  += 1;
        render_text(snake.score);
        play_effect(pick);
    }
}

void calc_new_position(SDL_Rect *rectangle)
{
    SDL_bool again = SDL_TRUE;
    while (again) {
    try_again:
        rectangle->x = (random() % 38 + 1) * 16;
        rectangle->y = (random() % 28 + 1) * 16;

        int i;
        for (i=0; i<snake.segcount; i++) {
            if (check_collision(&snake.segments[i], rectangle)) {
                goto try_again;
            }
        }

        for (i=0; i<level1_max_rect; i++) {
            if (check_collision(&level1[i], rectangle)) {
                goto try_again;
            }
        }

        again = SDL_FALSE;
    }
}

void render_text(int points)
{
    if (text) {
        SDL_FreeSurface(text);
    }

    char newtext[10];
    memset(newtext, 0, 10);
    sprintf(&newtext[0], "%02i", points);
    text = TTF_RenderText_Solid(font, newtext, fontcolor);
}

void check_collision_itself()
{

    int i;
    for (i=1; i<snake.segcount; i++) {
        if (check_collision(&snake.segments[0],
                &snake.segments[i])) {
            gameover = SDL_TRUE;
            play_effect(dead);
            break;
        }
    }
}

void play_effect(Mix_Chunk *chunk) {
    int channel = Mix_PlayChannel(-1, chunk, 0);
    if (channel < 0) {
        fprintf(stderr, "Unable to play wav file: %s\n",
            Mix_GetError());
        exit(EXIT_FAILURE);
    }
}

void render_rectangles(SDL_Rect *rects, int count)
{
    int i;
    for (i=0; i<count; i++) {
        SDL_FillRect(screen, &rects[i],
            SDL_MapRGB(screen->format, 0x0, 0x0, 0x0));
    }
}

void check_collisin_rectangles(SDL_Rect *rects, int count)
{
    int i;
    for (i=0; i<count; i++) {
        if (check_collision(&snake.segments[0], &rects[i])) {
            gameover = SDL_TRUE;
            play_effect(dead);
        }
    }

}
