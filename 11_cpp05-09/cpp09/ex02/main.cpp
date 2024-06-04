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
		long size = argc - 1;
		PmergeMe org(argv + 1, size);
		PmergeMe vec(org);
		PmergeMe deq(org);
		std::cout << "Before: ";
		org.printArr();

		if (!org.isSorted())
		{
			vec.sort<std::vector<unsigned int>, std::vector<std::pair<unsigned int, unsigned int> > >();
			deq.sort<std::deque<unsigned int>, std::deque<std::pair<unsigned int, unsigned int> > >();
			org = vec;
		}
		std::cout << "After:  ";
		org.printArr();
		vec.printTime("std::vector");
		deq.printTime("std::deque");
	}
	catch(std::exception const& e)
	{
		std::cout << "Error" << std::endl;
	}
	return 0;
}