#pragma once
#ifndef __PRESIDENTIAL_PARDON_FORM_H__
#define __PRESIDENTIAL_PARDON_FORM_H__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& org);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator = (const PresidentialPardonForm& org);
};

#endif