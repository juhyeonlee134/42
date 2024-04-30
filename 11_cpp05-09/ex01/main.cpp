#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main(void)
{
	Bureaucrat a("A", 5);
	Bureaucrat b("B", 7);
	Form form1("F", 10, 10);
	Form form2("G", 1, 1);

	try
	{
		std::cout << form1 << std::endl;
		a.signForm(form1);
		std::cout << form1 << std::endl;
		b.signForm(form1);
		std::cout << form2 << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}