#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>
#include <iostream>

Form::Form()
	: mName("noform")
	, mSignGrade(150)
	, mExecuteGrade(150)
	, mIsSigned(false)
{}

Form::Form(std::string const name, int const signGrade, int const executeGrade)
	: mName(name)
	, mSignGrade(signGrade)
	, mExecuteGrade(executeGrade)
	, mIsSigned(false)
{
	if (this->mSignGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->mSignGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
	if (this->mExecuteGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (this->mExecuteGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form const & org)
	: mName(org.getName())
	, mSignGrade(org.getSignGrade())
	, mExecuteGrade(org.getExecuteGrade())
	, mIsSigned(org.getIsSigned())
{}

Form & Form::operator = (Form const & org)
{
	std::cout << "Copy only signed" << std::endl;
	if (this == &org)
	{
		return *this;
	}
	this->mIsSigned = org.getIsSigned();
	return *this;
}

std::string Form::getName(void) const
{
	return this->mName;
}

int Form::getSignGrade(void) const
{
	return this->mSignGrade;
}

int Form::getExecuteGrade(void) const
{
	return this->mExecuteGrade;
}

bool Form::getIsSigned(void) const
{
	return this->mIsSigned;
}

void Form::beSigned(Bureaucrat const & b)
{
	if (this->mIsSigned)
	{
		throw Form::AlreadySigned();
	}
	else if (b.getGrade() > this->mSignGrade)
	{
		throw Form::GradeTooLowException();
	}
	this->mIsSigned = true;
}

const char * Form::GradeTooHighException::what(void) const throw()
{
	return "Form grade is too high";
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return "Form grade is too low";
}

const char * Form::AlreadySigned::what(void) const throw()
{
	return "Form is already signed";
}

std::ostream & operator << (std::ostream & os, Form const & f)
{
	os << f.getName() << " - ";
	os << "Sign grade : " << f.getSignGrade();
	os << " | Execute grade : " << f.getExecuteGrade();
	os << " | is signed : " << (f.getIsSigned() ? "O" : "X");
	return os;
}
