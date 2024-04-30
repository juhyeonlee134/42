#pragma once
#ifndef __SHRUBBETY_CREATION_FORM_H__
#define __SHRUBBETY_CREATION_FORM_H__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& org);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& org);
};

#endif