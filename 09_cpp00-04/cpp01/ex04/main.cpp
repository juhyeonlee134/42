#include "Sed.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: the number of argument must be 3" <<std::endl;
		return 1;
	}
	Sed sed = Sed(argv[2], argv[3]);
	sed.ConvertString(argv[1]);
	return 0;
}