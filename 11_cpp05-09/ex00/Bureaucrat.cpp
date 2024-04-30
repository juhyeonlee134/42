#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: mName("noname")
	, mGrade(0)
{}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: mName(name)
	, mGrade(grade)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& org)
{
	*this = org;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mName = org.getName();
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
		throw Bureaucrat::GradeTooHighException();
	this->mGrade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->mGrade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->mGrade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

