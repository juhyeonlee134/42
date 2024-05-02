#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a;
		Bureaucrat b("Bob", 70);
		Bureaucrat c("Charlie", 1);
		//Bureaucrat d("Daniel", -10);
		//Bureaucrat e("Edward", 200);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		//std::cout << d << std::endl;
		//std::cout << e << std::endl;
		//a.increaseGrade();
		//a.decreaseGrade();
		//a.decreaseGrade();
		b.increaseGrade();
		b.decreaseGrade();
		//c.increaseGrade();
		std::cout << "ret : " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
