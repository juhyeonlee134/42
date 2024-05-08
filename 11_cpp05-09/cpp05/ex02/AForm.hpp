#pragma once
#ifndef __A_FORM_H__
#define __A_FORM_H__

#include <string>
#include <ostream>

class Bureaucrat;

class AForm
{
public:
	AForm(std::string const name, std::string const target, int const signGrade, int const executeGrade);
	virtual ~AForm();
	std::string getName(void) const;
	std::string getTarget(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;
	Bureaucrat * getSign(void) const;
	void beSigned(Bureaucrat const & b);
	void checkSignAndGrade(Bureaucrat const & executor) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
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
	class SignedExcpetion : public std::runtime_error
	{
	public:
		SignedExcpetion(std::string const & msg);
	};
private:
	std::string const mName;
	std::string const mTarget;
	int const mSignGrade;
	int const mExecuteGrade;
	bool mIsSigned;
	AForm();
	AForm(AForm const & org);
	AForm & operator = (AForm const & org);
	Bureaucrat * mSign;
};

std::ostream & operator << (std::ostream & os, AForm const & f);

#endif
