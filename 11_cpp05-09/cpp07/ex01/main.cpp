#include "iter.hpp"
#include <iostream>
#include <exception>

int main(void)
{
	try
	{
		int arrInt[] = {1, 2, 3, 4, 5};
		std::size_t size = sizeof(arrInt) / sizeof(int);
		iter(arrInt, size, addTwo<int>);
		iter(arrInt, size, print<int>);

		double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
		size = sizeof(arrDouble) / sizeof(double);
		iter(arrDouble, size, addTwo<double>);
		iter(arrDouble, size, print<double>);

		std::string arrStr[] = {"aaa", "bbb", "ccc"};
		size = sizeof(arrStr) / sizeof(arrStr[0]);
		iter(arrStr, size, print<std::string>);
		iter(arrStr, -1, print<std::string>);
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}