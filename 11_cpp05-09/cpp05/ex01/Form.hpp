#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string name, const int signGrade, const int executeGrade);
	Form(const Form& org);
	~Form();
	Form& operator = (const Form& org);
	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;
	bool beSigned(const Bureaucrat& b);
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
	const int mSignGrade;
	const int mExecuteGrade;
	bool mIsSigned;
};

std::ostream& operator << (std::ostream& os, const Form& f);

#endif