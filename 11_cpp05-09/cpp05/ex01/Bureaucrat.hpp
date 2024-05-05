#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <ostream>

class Form;

class Bureaucrat
{
public:
	Bureaucrat(std::string const name, int const grade);
	~Bureaucrat();
	std::string getName(void) const;
	int getGrade(void) const;
	void increaseGrade(void);
	void signForm(Form & form) const;
	void decreaseGrade(void);
	class GradeTooHighException : public std::logic_error
	{
	public:
		GradeTooHighException(std::string const & msg);
	};
	class GradeTooLowException : public std::logic_error
	{
	public:
		GradeTooLowException(std::string const & msg);
	};
private:
	std::string const mName;
	int mGrade;
	Bureaucrat();
	Bureaucrat(Bureaucrat const & org);
	Bureaucrat & operator = (Bureaucrat const & org);
};

std::ostream & operator << (std::ostream & os, Bureaucrat const & b);

#endif
