#pragma once
#ifndef __PRESIDENTIAL_PARDON_FORM_H__
#define __PRESIDENTIAL_PARDON_FORM_H__

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(std::string const target);
	~PresidentialPardonForm();
	void execute(Bureaucrat const & executor) const;
private:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & org);
	PresidentialPardonForm & operator = (PresidentialPardonForm const & org);
};

#endif
