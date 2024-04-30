#pragma once
#ifndef __ROBOTOMY_REQUEST_FORM_H__
#define __ROBOTOMY_REQUEST_FORM_H__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& org);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator = (const RobotomyRequestForm& org);
};

#endif