#pragma once
#ifndef __A_FORM_H__
#define __A_FORM_H__

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm
{
public:
	AForm(const std::string name, const std::string target, const int signGrade, const int executeGrade);
	AForm(const AForm& org);
	~AForm();
	AForm& operator = (const AForm& org);
	std::string getName(void) const;
	std::string getTarget(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;
	bool beSigned(const Bureaucrat& b);
	virtual void execute(Bureaucrat const & executor);
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
	const std::string mTarget;
	const int mSignGrade;
	const int mExecuteGrade;
	bool mIsSigned;
	AForm();
};

std::ostream& operator << (std::ostream& os, const AForm& f);

#endif