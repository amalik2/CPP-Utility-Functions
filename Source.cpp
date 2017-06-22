#include "StringFunctions.h"

#include <iostream>

int main() {

	std::string str = "agkaga";

	StringFunctions::removeCharFromString(str, 'a');

	std::cout << str << std::endl;

	return 0;
}