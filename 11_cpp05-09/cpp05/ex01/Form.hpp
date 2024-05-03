#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include <ostream>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string const name, int const signGrade, int const executeGrade);
	Form(Form const & org);
	Form & operator = (Form const & org);
	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;
	void beSigned(Bureaucrat const & b);
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
	class AlreadySigned : public   std::exception
	{
	public:
		const char * what(void) const throw();
	};
private:
	std::string const mName;
	int const mSignGrade;
	int const mExecuteGrade;
	bool mIsSigned;
};

std::ostream & operator << (std::ostream & os, Form const & f);

#endif
