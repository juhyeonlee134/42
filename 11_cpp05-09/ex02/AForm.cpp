#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: mName("noname")
	, mToSignGrade(150)
	, mToExecuteGrade(150)
	, isSigned(false)
{}

AForm::AForm(const std::string name, const int toSignGrade, const int toExecuteGrade)
	: mName(name)
	, mToSignGrade(toSignGrade)
	, mToExecuteGrade(toExecuteGrade)
	, isSigned(false)
{
	if (this->mToSignGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->mToSignGrade > 150)
		throw AForm::GradeTooLowException();
	if (this->mToExecuteGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->mToExecuteGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& org)
	: mName(org.getName() + " copy")
	, mToSignGrade(org.getToSignGrade())
	, mToExecuteGrade(org.getToExecuteGrade())
	, isSigned(false)
{}

AForm::~AForm()
{}

AForm& AForm::operator = (const AForm& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->isSigned = org.getIsSigned();
	return *this;
}

std::string AForm::getName(void) const
{
	return this->mName;
}

bool AForm::getIsSigned(void) const
{
	return this->isSigned;
}

int AForm::getToSignGrade(void) const
{
	return this->mToSignGrade;
}

int AForm::getToExecuteGrade(void) const
{
	return this->mToExecuteGrade;
}

bool AForm::beSigned(const Bureaucrat& b)
{
	if (!this->isSigned && this->mToSignGrade > b.getGrade())
	{
		this->isSigned = true;
		return true;
	}
	else if (this->mToSignGrade < b.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	return false;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName();
	os << ", sign grade " << f.getToSignGrade();
	os << ", execute grade " << f.getToExecuteGrade();
	os << ", AForm signed " << f.getIsSigned();
	return os;
}