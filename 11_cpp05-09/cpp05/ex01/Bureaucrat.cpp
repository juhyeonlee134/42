#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat()
	: mName("noname")
	, mGrade(150)
{}

Bureaucrat::Bureaucrat(std::string const name, unsigned int const grade)
	: mName(name)
	, mGrade(grade)
{
	if (this->mGrade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (this->mGrade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & org)
	: mName(org.getName())
	, mGrade(org.getGrade())
{}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & org)
{
	std::cout << "Copy only the Grade." << std::endl;
	if (this == &org)
	{
		return *this;
	}
	this->mGrade = org.getGrade();
	return *this;
}

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
		throw Bureaucrat::GradeTooHighException();
	}
	this->mGrade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->mGrade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->mGrade++;
}

void Bureaucrat::signForm(Form & f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(Form::AlreadySigned const & e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because already signed" << std::endl;
	}
	catch(Form::GradeTooLowException const & e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because grade is too low" << std::endl;
	}
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat grade is too low";
}

std::ostream & operator << (std::ostream & os, Bureaucrat const & b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}
