#include <stdio.h>
#include <stdlib.h>

#include <cv.h>
#include <ml.h>
#include <cxcore.h>
#include <highgui.h>

int main(int argc,  char **argv)
{
	if (argc < 2) {
		printf("USAGE: %s <image>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	IplImage *img = cvLoadImage(argv[1], 1);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
	return 0;
}
