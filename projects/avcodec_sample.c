#include <avcodec.h>
#include <avformat.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("USAGE: %s <video_file>", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *errormsg = NULL; 

	/* intialize libavformat/libavcodec */
	av_register_all();

	AVFormatContext *formatctx;
	const char      *filename = argv[1];

	/* open video file */
	if (av_open_input_file(&formatctx, filename, NULL, 0, NULL) != 0) {
		errormsg =  "Couldn't open file";
		goto failure;
	}

	/* retrieve stream information */
	if (av_find_stream_info(formatctx) != 0) {
		errormsg = "Couldn't find stream information"
		goto failure;
	}

	return 0;

failure:
	fprintf(stderr, "%s\n", errormsg)
	return 1;
	
}
