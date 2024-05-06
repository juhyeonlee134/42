#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	ScalarConverter converter;
	try
	{
		converter.convert(argv[1]);
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
