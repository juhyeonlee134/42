#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int toSignGrade, const int toExecutGrade);
		Form(const Form& org);
		~Form();
		Form& operator = (const Form& org);
		std::string getName(void) const;
		bool getIsSigned(void) const;
		int getToSignGrade(void) const;
		int getToExecuteGrade(void) const;
		bool beSigned(const Bureaucrat& b);
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

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif