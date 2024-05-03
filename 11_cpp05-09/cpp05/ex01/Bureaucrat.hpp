#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <ostream>

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string const name, unsigned int const grade);
	Bureaucrat(Bureaucrat const & org);
	Bureaucrat & operator = (Bureaucrat const & org);
	std::string getName(void) const;
	int getGrade(void) const;
	void increaseGrade(void);
	void decreaseGrade(void);
	void signForm(Form & f);
	class GradeTooHighException : public std::exception
	{
	public:
		const char * what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char * what(void) const throw();
	};
private:
	std::string const mName;
	int mGrade;
};

std::ostream & operator << (std::ostream & os, Bureaucrat const & b);

#endif
