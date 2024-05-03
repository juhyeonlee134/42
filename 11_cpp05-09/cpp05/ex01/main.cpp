#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("AAA", 10);
		Form contract1("banziha", 100, 50);
		Form contract2("gangnam apt", 1, 10);
		//Form wrong("wrong", 2147483647, 2147483647);
		//Form wrong("wrong", -2147483648, -2147483648);
		a.signForm(contract1);
		a.signForm(contract2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
