#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>
#include <ostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& org);
		~Bureaucrat();
		Bureaucrat& operator = (const Bureaucrat& org);
		std::string getName(void) const;
		int getGrade(void) const;
		void increaseGrade(void);
		void decreaseGrade(void);
		void signForm(Form& f);
		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:
		const std::string mName;
		int mGrade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
