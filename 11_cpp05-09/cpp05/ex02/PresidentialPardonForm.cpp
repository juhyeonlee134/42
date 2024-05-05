#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkSignAndGrade(executor);
	std::cout << "President Zaphod Beeblebrox pardoned " << executor.getName() << '\n';
}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & org)
	: AForm(org.getName(), org.getTarget(), org.getSignGrade(), org.getExecuteGrade())
{}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}
