#include <stdio.h>
#include <stdlib.h>

#include <cv.h>
#include <ml.h>
#include <cxcore.h>
#include <highgui.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
			printf("USAGE: %s <video_in>", argv[0]);
		exit(EXIT_FAILURE);
	}

	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);

	CvCapture *capture = cvCreateFileCapture(argv[1]);
	IplImage  *frame = NULL;

	while (1) {
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("Example2", frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}

	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
	return 0;

	
}
