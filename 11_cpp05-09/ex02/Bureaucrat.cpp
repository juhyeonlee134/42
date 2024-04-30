#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
	: mName("noname")
	, mGrade(150)
{}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
	: mName(name)
	, mGrade(grade)
{
	if (this->mGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->mGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& org)
	: mName(org.getName() + " copy")
	, mGrade(org.getGrade())
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& org)
{
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
		throw Bureaucrat::GradeTooHighException();
	this->mGrade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->mGrade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->mGrade++;
}

void Bureaucrat::signForm(AForm& f)
{
	if (f.beSigned(*this))
	{
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	else
	{
		std::cout << this->getName() << " couldn't sign " << f.getName();
		std::cout << " because ";
		if (f.getToSignGrade() < this->getGrade())
		{
			std::cout << "grade too low";
		}
		else
		{
			std::cout << "already signed";
		}
		std::cout << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

