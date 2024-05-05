#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkSignAndGrade(executor);
	std::srand(std::time(NULL));
	std::cout << executor.getName() << " robotomizes " << (std::rand() % 2 ? "successed" : "failed") << '\n';
}

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & org)
	: AForm(org.getName(), org.getTarget(), org.getSignGrade(), org.getExecuteGrade())
{}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const & org)
{
	if (this == & org)
	{
		return *this;
	}
	return *this;
}
