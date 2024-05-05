#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(Intern const & org)
{
	*this = org;
}

Intern & Intern::operator = (Intern const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}

AForm * Intern::makeForm(std::string name, std::string target)
{
	AForm * form = NULL;
	std::string stringArray[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	enum EForm formNum = NOFORM;
	for (std::size_t index = 0; index < 3; index++)
	{
		if (stringArray[index] == name)
		{
			formNum = (enum EForm)(index + 1);
		}
	}
	switch(formNum)
	{
		case SHRUBBERY :
			form = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMY :
			form = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL :
			form = new PresidentialPardonForm(target);
			break;
		default :
			throw std::invalid_argument("name is wrong");
	}
	if (form == NULL)
	{
		throw std::bad_alloc();
	}
	return form;
}
