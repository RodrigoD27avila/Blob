#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "pantsu/Support/String.h"
using namespace pantsu;

int main()
{
	String *str = new String();

	str->append("Programming");
	assert(str->length() > 0);

	str->append(" in C++.");
	assert(str->length() > 0);

	int i;
	for (i=0; i < str->length(); i++) {
		char c = str->character(i);
		assert(c != '\0');
	}

	size_t clen = strlen(str->data());
	size_t mlen = (size_t)str->length();
	assert(clen == mlen);

	assert(str->character(mlen+1) == '\0');

	size_t print = printf("%s", str->data());
	printf("\n");

	assert(print == mlen);

	delete str;
}
