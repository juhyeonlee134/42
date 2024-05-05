#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
public:
	Form(std::string const name, int const signGrade, int const executeGrade);
	~Form();
	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;
	void beSigned(Bureaucrat const & b);
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
	class AlreadySigned : public std::logic_error
	{
	public:
		AlreadySigned();
	};
private:
	std::string const mName;
	int const mSignGrade;
	int const mExecuteGrade;
	bool mIsSigned;
	Form();
	Form(Form const & org);
	Form & operator = (Form const & org);
};

std::ostream & operator << (std::ostream & os, Form const & f);

#endif
