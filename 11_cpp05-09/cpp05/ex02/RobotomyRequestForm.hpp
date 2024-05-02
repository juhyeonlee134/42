#pragma once
#ifndef __ROBOTOMY_REQUEST_FORM_H__
#define __ROBOTOMY_REQUEST_FORM_H__

#include "AForm.hpp"
#include <string>
#include <exception>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& org);
	RobotomyRequestForm& operator = (const RobotomyRequestForm& org);
	void execute(Bureaucrat const & executor);
	class CannotExecute : public std::exception
	{
		virtual const char* what(void) const throw();
	};
private:
	static int num;
	RobotomyRequestForm();
};

#endif