#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
	Bureaucrat a("A", 5);
	Bureaucrat b("B", 10);
	Bureaucrat c(b);

	try
	{
		for (size_t index = 0; index < 140; index++)
		{
			c.decreaseGrade();
			std::cout << c << std::endl;
		}
		for (size_t index = 0; index < 10; index++)
		{
			a.increaseGrade();
			std::cout << a << std::endl;
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}