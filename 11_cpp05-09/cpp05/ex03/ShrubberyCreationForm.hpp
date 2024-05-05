#pragma once
#ifndef __SHRUBBERY_CREATION_FORM_H__
#define __SHRUBBERY_CREATION_FORM_H__

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const & executor) const;
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & org);
	ShrubberyCreationForm & operator = (ShrubberyCreationForm const & org);
};

#endif
