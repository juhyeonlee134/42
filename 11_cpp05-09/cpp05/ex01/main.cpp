#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main(void)
{
	try
	{
		Bureaucrat a("AAA", 10);
		Bureaucrat b("BBB", 100);
		Bureaucrat c("CCC", 1);
		Form f("Form", 50, 50);
		// Form g("Gorm", 0, 50);
		// Form h("Horm", 200, 50);
		// Form I("Iorm", 50, 0);
		// Form J("Jorm", 50, 200);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << f << std::endl;
		a.signForm(f);
		b.signForm(f);
		c.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}