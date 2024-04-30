#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string name, const int toSignGrade, const int toExecutGrade);
		AForm(const AForm& org);
		~AForm();
		AForm& operator = (const AForm& org);
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getToSignGrade(void) const;
		int getToExecuteGrade(void) const;
		bool beSigned(const Bureaucrat& b);
		virtual bool execute(Bureaucrat const & executor) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:
		const std::string mName;
		const int mToSignGrade;
		const int mToExecuteGrade;
		bool isSigned;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif