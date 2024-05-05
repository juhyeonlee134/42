#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("AAA", 1);
		Bureaucrat b("BBB", 70);
		Bureaucrat c("CCC", 150);
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';

		Form f1("Form1", 1 ,1);
		Form f2("Form2", 70, 70);
		//Form f3("Form3", 0, 70);
		//Form f4("Form4", 200, 70);
		//Form f5("Form5", 70, 0);
		//Form f6("Form6", 70, 200);
		//Form f7("Form", -1, -1);
		std::cout << f1 << '\n';
		std::cout << f2 << '\n';

		c.signForm(f1);
		b.signForm(f1);
		a.signForm(f1);
		std::cout << f1 << '\n';

		c.signForm(f2);
		b.signForm(f2);
		a.signForm(f2);
		std::cout << f2 << '\n';
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}

}
