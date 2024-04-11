#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: the number of arguments must be 1" << std::endl;
		return 1;
	}
	Harl harl = Harl();
	harl.complain(argv[1]);
	return 0;
}