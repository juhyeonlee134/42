#pragma once
#ifndef __INTERN_H__
#define __INTERN_H__

#include <string>

class AForm;

enum EForm
{
	NOFORM,
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL
};

class Intern
{
public:
	Intern();
	Intern(Intern const & org);
	~Intern();
	Intern & operator = (Intern const & org);
	AForm * makeForm(std::string name, std::string target);
};

#endif
