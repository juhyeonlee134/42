#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <exception>
#include <ostream>

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string name, const int mGrade);
	Bureaucrat(const Bureaucrat& org);
	~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat& org);
	std::string getName(void) const;
	int getGrade(void) const;
	void increaseGrade(void);
	void decreaseGrade(void);
	void signForm(Form& f) const;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what(void) const throw();
	};
private:
	const std::string mName;
	int mGrade;
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& b);

#endif