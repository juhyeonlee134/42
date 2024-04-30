#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: mName("noname")
	, mToSignGrade(150)
	, mToExecuteGrade(150)
	, isSigned(false)
{}

Form::Form(const std::string name, const int toSignGrade, const int toExecuteGrade)
	: mName(name)
	, mToSignGrade(toSignGrade)
	, mToExecuteGrade(toExecuteGrade)
	, isSigned(false)
{
	if (this->mToSignGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->mToSignGrade > 150)
		throw Form::GradeTooLowException();
	if (this->mToExecuteGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->mToExecuteGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& org)
	: mName(org.getName() + " copy")
	, mToSignGrade(org.getToSignGrade())
	, mToExecuteGrade(org.getToExecuteGrade())
	, isSigned(false)
{}

Form::~Form()
{}

Form& Form::operator = (const Form& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->isSigned = org.getIsSigned();
	return *this;
}

std::string Form::getName(void) const
{
	return this->mName;
}

bool Form::getIsSigned(void) const
{
	return this->isSigned;
}

int Form::getToSignGrade(void) const
{
	return this->mToSignGrade;
}

int Form::getToExecuteGrade(void) const
{
	return this->mToExecuteGrade;
}

bool Form::beSigned(const Bureaucrat& b)
{
	if (!this->isSigned && this->mToSignGrade > b.getGrade())
	{
		this->isSigned = true;
		return true;
	}
	else if (this->mToSignGrade < b.getGrade())
	{
		throw Form::GradeTooLowException();
	}
	return false;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName();
	os << ", sign grade " << f.getToSignGrade();
	os << ", execute grade " << f.getToExecuteGrade();
	os << ", form signed " << f.getIsSigned();
	return os;
}