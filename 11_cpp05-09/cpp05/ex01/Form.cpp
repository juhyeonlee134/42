#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

Form::Form()
	: mName("noname")
	, mSignGrade(75)
	, mExecuteGrade(75)
	, mIsSigned(false)
{}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
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

Form::Form(const Form& org)
	: mName(org.getName() + " copy")
	, mSignGrade(org.getSignGrade())
	, mExecuteGrade(org.getExecuteGrade())
	, mIsSigned(org.getIsSigned())
{}

Form::~Form()
{}

Form& Form::operator = (const Form& org)
{
	if (this != &org)
	{
		this->mIsSigned = org.getIsSigned();
	}
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

bool Form::beSigned(const Bureaucrat& b)
{
	// what is mean "if the grade is too low?"
	if (this->mIsSigned || b.getGrade() > this->mSignGrade)
	{
		return false;
	}
	this->mIsSigned = true;
	return true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Form grade too low";
}

std::ostream& operator << (std::ostream& os, const Form& f)
{
	os << f.getName();
	os << ", sign grade " << f.getSignGrade();
	os << ", execute grade " << f.getExecuteGrade();
	os << ", signed " << (bool)f.getIsSigned();
	return os;
}