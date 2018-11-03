#include <stdio.h>
#include <stdlib.h>

#include <cv.h>
#include <ml.h>
#include <cxcore.h>
#include <highgui.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("USAGE: %s <image>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	IplImage *img  = cvLoadImage(argv[1], 1);
	cvNamedWindow("Example3-in", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example3-out", CV_WINDOW_AUTOSIZE);

	/* show the original image */
	cvShowImage("Example3-in", img);

	/* create image for out */
	IplImage *out = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
	
	/* perform gaussian blur */
	cvSmooth(img, out, CV_GAUSSIAN, 111, 111, 0, 0);

	/* show the processed image */
	cvShowImage("Example3-out", out);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&out);
	cvDestroyWindow("Example-in");
	cvDestroyWindow("Example-out");
	return 0;
}
