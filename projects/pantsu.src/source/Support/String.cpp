#include "pantsu/Support/String.h"

namespace pantsu {

static u32 StrLen(const char *s);

struct DLL_LOCAL StringPrivate {
	u32  length;
	char *data;
};

String::String()
{
	// create new String_Private object
	priv = new StringPrivate();
	priv->length   = 0;
	priv->data     = NULL;
}

String::~String()
{
	// delete data
	delete[] priv->data;

	// delete priv
	delete   priv;
}

u32 String::length()
{
	// legth of the string
	return priv->length;
}

void String::clear()
{
	// first clear the data
	delete[] priv->data;

	// set data to NULL and lenght to 0
	priv->data   = NULL;
	priv->length = 0;
}

void String::append(const char *text)
{
	// allocate new string based on len
	u32  len   = priv->length + StrLen(text);
	char *dest = new char[len + 1];

	// counters
	u32 count = 0;
	u32 i     = 0;

	// first string
	for(i=0; priv->length > 0 && priv->data[i] != '\0'; i++) {
		dest[count++] = priv->data[i];
	}

	// second string
	for (i=0; text[i] != '\0'; i++) {
		dest[count++] = text[i];
	}

	// delete old data
	if (priv->data != NULL) {
		delete[] priv->data;
	}

	// set data and length
	priv->data   = dest;
	priv->length = len;
}

bool String::isEmpty()
{
	// check if lenght is equals to 0
	return (priv->length == 0);
}

char String::character(u32 index)
{
	// return character at n position
	return priv->data[index];
}

char *String::data()
{
	// return the pointer to data
	return priv->data;
}

static u32 StrLen(const char *s)
{
	// check if string is NULL 
	if (s == NULL) {
		return 0;
	}

	// get string length
	u32 count;
	for(count=0; s[count] != '\0'; count++);

	// return length
	return count;
}

} // end namespace pantsu
