#include <iostream>

#include "config.hpp"

int main() {
	std::cout << VERSION_MAJOR << '.';
	std::cout << VERSION_MINOR << '.';
	std::cout << VERSION_PATCH << std::endl;

	return 0;
}
