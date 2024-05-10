#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main(void)
{
	Array<int> intArr(3);
	Array<float> floatArry(5);
	try
	{
		for (unsigned int index = 0; index < intArr.size(); index++)
		{
			intArr[index] = index + 1;
		}
		for (unsigned int index = 0; index < intArr.size(); index++)
		{
			std::cout << intArr[index] << ' ';
		}
		std::cout << '\n';
		for (unsigned int index = 0; index < floatArry.size(); index++)
		{
			floatArry[index] = index + 1.1;
		}
		for (unsigned int index = 0; index < floatArry.size(); index++)
		{
			std::cout << floatArry[index] << ' ';
		}
		std::cout << '\n';
		std::cout << intArr[-1] << '\n';
		std::cout << intArr[100] << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}