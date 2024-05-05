#include "Intern.hpp"
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
		Bureaucrat a("AAA", 100);
		Intern intern;
		AForm * form = intern.makeForm("shrubbery creation", "house");
		std::cout << *form << '\n';

		a.signForm(*form);
		a.executeForm(*form);
		delete form;

		Bureaucrat b("BBB", 30);
		form = intern.makeForm("robotomy request", "dog");
		std::cout << *form << '\n';

		b.signForm(*form);
		b.executeForm(*form);
		delete form;

		Bureaucrat c("CCC", 1);
		form = intern.makeForm("presidential pardon", "who");
		std::cout << *form << '\n';

		c.signForm(*form);
		c.executeForm(*form);
		delete form;
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
