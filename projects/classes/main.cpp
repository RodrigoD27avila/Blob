#include <stdio.h>

#include "settings.h"
#include "sprite.h"

using namespace Classes;

int main()
{
	Sprite s;
	s.createFromImage("lol");
	printf("w = %u\n", s.getWidth());
	printf("h = %u\n", s.getHeight());
	printf("b = %u\n", s.getBpp());
	printf("p = %p\n", s.getPixels());

	int *ii = (int*)0xCAFEBABE;
	printf("p = %p\n", ii);
	delete ii;
	return 0;
}

