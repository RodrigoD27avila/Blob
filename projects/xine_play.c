#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
#if 0
    if(argc <= 1)
    {
        fprintf(stderr,"Usage %s some_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    xine_t            *engine;
    xine_audio_port_t *audiop;
    xine_video_port_t *videop;
    xine_stream_t     *stream;

    engine = xine_new();
    xine_init(engine);

    audiop = xine_open_audio_driver(engine, NULL, NULL);
    videop = xine_open_video_driver(engine, NULL, XINE_VISUAL_TYPE_NONE, NULL);

    stream = xine_stream_new(engine, audiop, videop);

    char *path = argv[1];
    strcat(path, "#demux:ogg");

    xine_open(stream, path);
    xine_play(stream, 0, 0);
#endif

    char quit = 0;

    do{

        printf("use q to quit.\n");
        quit = getchar();

    }
    while(quit != 'q');

#if 0
    xine_close(stream);
    xine_close_audio_driver(engine, audiop);
    xine_close_video_driver(engine, videop);
    xine_exit(engine);
#endif

    return EXIT_SUCCESS;
}
