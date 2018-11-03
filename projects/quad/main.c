#include <stdio.h>
#include "unistd.h"
#include "quadint.h"

int main()
{
	QEGLInit(NULL);
	Quad_Window *window = QCreateWindow("Teste", 0, 0, 640, 480);
	printf("%dx%d\n", window->native.width, window->native.height);

	sleep(100);

	return 0;
}
