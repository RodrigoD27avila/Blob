#include <iostream>

template<typename T>
class equal_comparable {
	friend bool operator==(T const &a, T const &b) {
		return a.equal_to(b);
	}

	friend bool operator!=(T const &a, t const &b) {
		return !a.equal_to(b);
	}
};
