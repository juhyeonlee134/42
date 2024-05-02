#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "notarget", 150, 150)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm" + num, target, 72, 45)
{
	this->num++;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& org)
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (!this->getIsSigned() || executor.getGrade() > this->getExecuteGrade())
	{
		throw RobotomyRequestForm::CannotExecute();
	}
	std::cout << "driii..." << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));
	int randomNum = std::rand() % 2;
	if (randomNum)
	{
		std::cout << this->getTarget() << " is success to Robotomy" << std::endl;
	}
	else
	{
		std::cout << this->getTarget() << " is failed to Robotomy" << std::endl;
	}
}