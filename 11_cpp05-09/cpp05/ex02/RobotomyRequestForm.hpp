#pragma once
#ifndef __ROBOTOMY_REQUEST_FORM_H__
#define __ROBOTOMY_REQUEST_FORM_H__

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(std::string const target);
	~RobotomyRequestForm();
	void execute(Bureaucrat const & executor) const;
private:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & org);
	RobotomyRequestForm & operator = (RobotomyRequestForm const & org);
};

#endif
