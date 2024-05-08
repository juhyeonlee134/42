#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm(std::string const name, std::string const target, int const signGrade, int const executeGrade)
	: mName(name)
	, mTarget(target)
	, mSignGrade(signGrade)
	, mExecuteGrade(executeGrade)
	, mIsSigned(false)
	, mSign(NULL)
{
	if (this->mSignGrade < 1)
	{
		throw AForm::GradeTooHighException("Initial sign rating is too high.");
	}
	else if (this->mSignGrade > 150)
	{
		throw AForm::GradeTooLowException("Initial sign rating is too low.");
	}
	if (this->mExecuteGrade < 1)
	{
		throw AForm::GradeTooHighException("Initial execution rating is too high.");
	}
	else if (this->mExecuteGrade > 150)
	{
		throw AForm::GradeTooLowException("Initial execution rating is too low.");
	}
}

AForm::~AForm()
{}

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

Bureaucrat * AForm::getSign(void) const
{
	return this->mSign;
}

void AForm::beSigned(Bureaucrat const & b)
{
	if (this->mIsSigned)
	{
		throw AForm::AlreadySigned();
	}
	else if (b.getGrade() > this->mSignGrade)
	{
		throw AForm::GradeTooLowException("the sign grade is low");
	}
	this->mIsSigned = true;
	this->mSign = (Bureaucrat *)(&b);
}

void AForm::checkSignAndGrade(Bureaucrat const & executor) const
{
	if (!this->mIsSigned)
	{
		throw AForm::SignedExcpetion("need sign");
	}
	else if (this->mSign != &executor)
	{
		throw AForm::SignedExcpetion("not signed this form");
	}
	else if (executor.getGrade() > this->mExecuteGrade)
	{
		throw AForm::GradeTooLowException("The grade is low to execute");
	}
}

AForm::GradeTooHighException::GradeTooHighException(std::string const & msg)
	: std::logic_error(msg)
{}

AForm::GradeTooLowException::GradeTooLowException(std::string const & msg)
	: std::logic_error(msg)
{}

AForm::AlreadySigned::AlreadySigned()
	: std::logic_error("already signed")
{}

AForm::SignedExcpetion::SignedExcpetion(std::string const & msg)
	: std::runtime_error(msg)
{}

AForm::AForm()
	: mName("")
	, mTarget("")
	, mSignGrade(150)
	, mExecuteGrade(150)
	, mIsSigned(false)
{}

AForm::AForm(AForm const & org)
	: mName(org.getName())
	, mTarget(org.getTarget())
	, mSignGrade(org.getSignGrade())
	, mExecuteGrade(org.getExecuteGrade())
	, mIsSigned(false)
{}

AForm & AForm::operator = (AForm const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}

std::ostream & operator << (std::ostream & os, AForm const & f)
{
	os << f.getName() << " AForm" << '\n';
	os << '\t' << "target : " << f.getTarget() << '\n';
	os << '\t' << "sign grade : " << f.getSignGrade() << '\n';
	os << '\t' << "execute grade : " << f.getExecuteGrade() << '\n';
	os << '\t' << "is signed : " << (f.getIsSigned() ? "O" : "X");
	Bureaucrat * sign = f.getSign();
	if (sign != NULL)
	{
		os << " by " << sign->getName();
	}
	return os;
}
