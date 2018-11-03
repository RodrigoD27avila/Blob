#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#include "resource.h"
#include "window.h"
#include "settings.h"
#include "pstring.h"

int main()
{
	settings_Init();
	window_Init();
	resource_Init();

	string_t str;
	string_init(&str);

	string_catconst(&str, "Rodrigo");

	printf("%s  s = %u c = %u\n", string_get(&str), str.size, str.capacity);

	string_setconst(&str, "gggg");

	printf("%s  s = %u c = %u\n", string_get(&str), str.size, str.capacity);

	string_catconst(&str, "RODRIGO D\'AVILA");

	printf("%s  s = %u c = %u\n", string_get(&str), str.size, str.capacity);

	string_setconst(&str, "FUU");

	printf("%s  s = %u c = %u\n", string_get(&str), str.size, str.capacity);

	int i;
	for (i=0; i<str.capacity; i++) {
		printf("%i ", (int)string_at(&str, i));
	}
	printf("\n");

	string_destroy(&str);
	resource_Quit();
	window_Quit();

	return 0;
}
