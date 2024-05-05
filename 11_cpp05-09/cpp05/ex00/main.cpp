#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("AAA", 1);
		Bureaucrat b("BBB", 70);
		Bureaucrat c("CCC", 150);
		//Bureaucrat d("DDD", 0);
		//Bureaucrat e("EEE", 200);
		//Bureaucrat f("FFF", -1);
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';

		a.increaseGrade();
		b.increaseGrade();
		c.increaseGrade();
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}

}
