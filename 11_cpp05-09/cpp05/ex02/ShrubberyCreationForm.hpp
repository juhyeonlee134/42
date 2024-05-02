#pragma once
#ifndef __SHRUBBERY_CREATION_FORM_H__
#define __SHRUBBERY_CREATION_FORM_H__

#include "AForm.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm
{
public :
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& org);
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& org);
	void execute(Bureaucrat const & executor);
	class CannotExecute : public std::exception
	{
		virtual const char* what(void) const throw();
	};
private:
	static int num;
	ShrubberyCreationForm();
};

#endif