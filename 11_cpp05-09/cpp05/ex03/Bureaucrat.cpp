#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(std::string const name, int const grade)
	: mName(name)
	, mGrade(grade)
{
	if (this->mGrade < 1)
	{
		throw Bureaucrat::GradeTooHighException("The initial rating is too high");
	}
	else if (this->mGrade > 150)
	{
		throw Bureaucrat::GradeTooLowException("The initial rating is too low");
	}
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName(void) const
{
	return this->mName;
}

int Bureaucrat::getGrade(void) const
{
	return this->mGrade;
}

void Bureaucrat::increaseGrade(void)
{
	if (this->mGrade == 1)
	{
		throw Bureaucrat::GradeTooHighException("It's already the highest grade.");
	}
	this->mGrade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->mGrade == 150)
	{
		throw Bureaucrat::GradeTooLowException("It's already at its lowest grade.");
	}
	this->mGrade++;
}

void Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->mName << " signed " << form.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << this->mName << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->mName << " executed " << form.getName() << '\n';
	}
	catch(std::exception const & e)
	{
		std::cout << this->mName << " couldn't execute " << form.getName() << " becase " << e.what() << '\n';
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string const & msg)
	: std::logic_error(msg)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string const & msg)
	: std::logic_error(msg)
{}

Bureaucrat::Bureaucrat()
	: mName("")
	, mGrade(150)
{}

Bureaucrat::Bureaucrat(Bureaucrat const & org)
	: mName(org.getName())
	, mGrade(org.getGrade())
{}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}

std::ostream & operator << (std::ostream & os, Bureaucrat const & b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
