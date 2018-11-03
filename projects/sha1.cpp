#include <iostream>
#include <sstream>
#include <boost/uuid/sha1.hpp>

int main()
{
	boost::uuids::detail::sha1 sha1;
	unsigned int hash[5];

	const char *name = "1";

	sha1.process_bytes(name, 7);
	sha1.get_digest(hash);

	std::stringstream ss;
	for(int i=0; i<5; i++) {
		ss << std::hex << hash[i];
	}

	std::cout << ss.str() << std::endl;

}
