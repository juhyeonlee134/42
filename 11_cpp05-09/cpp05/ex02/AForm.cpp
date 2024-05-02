#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

AForm::AForm()
	: mName("noname")
	, mTarget("")
	, mSignGrade(75)
	, mExecuteGrade(75)
	, mIsSigned(false)
{}


AForm::AForm(const std::string name, const std::string target, const int signGrade, const int executeGrade)
	: mName(name)
	, mTarget(target)
	, mSignGrade(signGrade)
	, mExecuteGrade(executeGrade)
	, mIsSigned(false)
{
	if (this->mSignGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->mSignGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
	if (this->mExecuteGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (this->mExecuteGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm(const AForm& org)
	: mName(org.getName() + " copy")
	, mSignGrade(org.getSignGrade())
	, mExecuteGrade(org.getExecuteGrade())
	, mIsSigned(org.getIsSigned())
{}

AForm::~AForm()
{}

AForm& AForm::operator = (const AForm& org)
{
	if (this != &org)
	{
		this->mIsSigned = org.getIsSigned();
	}
	return *this;
}

std::string AForm::getName(void) const
{
	return this->mName;
}

std::string AForm::getTarget(void) const
{
	return this->mTarget;
}

int AForm::getSignGrade(void) const
{
	return this->mSignGrade;
}

int AForm::getExecuteGrade(void) const
{
	return this->mExecuteGrade;
}

bool AForm::getIsSigned(void) const
{
	return this->mIsSigned;
}

bool AForm::beSigned(const Bureaucrat& b)
{
	// what is mean "if the grade is too low?"
	if (this->mIsSigned || b.getGrade() > this->mSignGrade)
	{
		return false;
	}
	this->mIsSigned = true;
	return true;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm grade too low";
}

std::ostream& operator << (std::ostream& os, const AForm& f)
{
	os << f.getName();
	os << ", sign grade " << f.getSignGrade();
	os << ", execute grade " << f.getExecuteGrade();
	os << ", signed " << (bool)f.getIsSigned();
	return os;
}