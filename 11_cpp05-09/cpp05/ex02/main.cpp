#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat a("AAA", 1);
		Bureaucrat b("BBB", 40);
		Bureaucrat c("CCC", 130);
		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';

		ShrubberyCreationForm sForm("Home");
		RobotomyRequestForm rForm("Cat");
		PresidentialPardonForm pForm("DDD");
		std::cout << sForm << '\n';
		std::cout << rForm << '\n';
		std::cout << pForm << '\n';

		c.signForm(sForm);
		c.signForm(rForm);
		c.signForm(pForm);
		b.signForm(sForm);
		b.signForm(rForm);
		b.signForm(pForm);
		a.signForm(sForm);
		a.signForm(rForm);
		a.signForm(pForm);
		std::cout << sForm << '\n';
		std::cout << rForm << '\n';
		std::cout << pForm << '\n';
		
		c.executeForm(sForm);
		c.executeForm(rForm);
		c.executeForm(pForm);
		b.executeForm(sForm);
		b.executeForm(rForm);
		b.executeForm(pForm);
		a.executeForm(sForm);
		a.executeForm(rForm);
		a.executeForm(pForm);
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
