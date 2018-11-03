#ifndef PANTSU_SUPPORT_STRING_H
#define PANTSU_SUPPORT_STRING_H

#include "pantsu/Core.h"

namespace pantsu {

struct StringPrivate;

class DLL_PUBLIC String {
public:
	/// get the lenght of the String
	u32    length();

	/// clear String data
	void   clear();

	/// append array of character to the end of the String
	void   append(const char *text);
	
	/// check if the String is empty
	bool   isEmpty();

	/// get character of the string
	char   character(u32 index);

	/// get the string data
	char   *data();

	/// creates an instance of the String class
	String();

	/// delete this instance of the String class
	~String();
private:
	StringPrivate *priv;
};

} // end namespace pantsu

#endif // PANTSU_SUPPORT_STRING_H
