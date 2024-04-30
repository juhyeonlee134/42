#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main(void)
{
	try
	{
		Bureaucrat a("AAA", 1);
		Bureaucrat b("BBB", 80);
		Bureaucrat c("CCC", 150);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		b.increaseGrade();
		std::cout << b << std::endl;
		b.decreaseGrade();
		std::cout << b << std::endl;
		// Bureaucrat d("DDD", 200);
		// Bureaucrat e("EEE", 0);
		// a.increaseGrade();
		// c.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}