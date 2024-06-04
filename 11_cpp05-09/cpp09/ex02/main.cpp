#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe fordJohnson(argv + 1, argc - 1);
        if (fordJohnson.isSorted())
        {
            fordJohnson.printArr();
        }
        else
		{
            fordJohnson.sort();
        }
	}
	catch(std::exception const& e)
	{
		std::cout << "Error" << std::endl;
	}
	return 0;
}