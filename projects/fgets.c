#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("rodrigo.txt", "r");

	char buff[20];
	char str[20];

	while (!feof(f)) {

		memset(buff, 0, 20);
		memset(str, 0, 20);

		fgets(buff, 19, f);

		int len = strlen(buff);
		if (len <= 0) {
			continue;
		}

		memcpy(str, buff, len -1);
		printf("%s", str);
	}
	return 0;
}
