#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

Form::Form(std::string const name, int const signGrade, int const executeGrade)
	: mName(name)
	, mSignGrade(signGrade)
	, mExecuteGrade(executeGrade)
	, mIsSigned(false)
{
	if (this->mSignGrade < 1)
	{
		throw Form::GradeTooHighException("Initial sign rating is too high.");
	}
	else if (this->mSignGrade > 150)
	{
		throw Form::GradeTooLowException("Initial sign rating is too low.");
	}
	if (this->mExecuteGrade < 1)
	{
		throw Form::GradeTooHighException("Initial execution rating is too high.");
	}
	else if (this->mExecuteGrade > 150)
	{
		throw Form::GradeTooLowException("Initial execution rating is too low.");
	}
}

Form::~Form()
{}

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
		throw Form::GradeTooLowException("the sign grade is low");
	}
	this->mIsSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(std::string const & msg)
	: std::logic_error(msg)
{}

Form::GradeTooLowException::GradeTooLowException(std::string const & msg)
	: std::logic_error(msg)
{}

Form::AlreadySigned::AlreadySigned()
	: std::logic_error("already signed")
{}

Form::Form()
	: mName("")
	, mSignGrade(150)
	, mExecuteGrade(150)
	, mIsSigned(false)
{}

Form::Form(Form const & org)
	: mName(org.getName())
	, mSignGrade(org.getSignGrade())
	, mExecuteGrade(org.getExecuteGrade())
	, mIsSigned(false)
{}

Form & Form::operator = (Form const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}

std::ostream & operator << (std::ostream & os, Form const & f)
{
	os << f.getName() << " form" << '\n';
	os << '\t' << "sign grade : " << f.getSignGrade() << '\n';
	os << '\t' << "execute grade : " << f.getExecuteGrade() << '\n';
	os << '\t' << "is signed : " << (f.getIsSigned() ? "O" : "X");
	return os;
}
