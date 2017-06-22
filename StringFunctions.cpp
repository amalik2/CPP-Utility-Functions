#include "StringFunctions.h"

#include <algorithm>

namespace StringFunctions
{

	void removeCharFromString(std::string &str, char ch) {
		str.erase(std::remove(str.begin(), str.end(), ch), str.end());
	}

}