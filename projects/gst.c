#include <stdio.h>
#include <stdlib.h>

#include <gst/gst.h>

int main(int argc, char **argv)
{
	guint major, minor, micro, nano;

	gst_init(&argc, &argv);
	gst_version(&major, &minor, &micro, &nano);

	printf("GStreamer version: %d.%d.%d %d\n", major, minor, micro, nano);
	return 0;
}
