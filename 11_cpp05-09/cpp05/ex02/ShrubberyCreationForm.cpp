#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "notarget", 150, 150)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm" + num, target, 145, 137)
{
	this->num++;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& org)
	: AForm(org.getName(), org.getTarget(), org.getSignGrade(), org.getExecuteGrade())
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& org)
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (!this->getIsSigned() || executor.getGrade() > this->getExecuteGrade())
	{
		throw ShrubberyCreationForm::CannotExecute();
	}
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file.is_open())
	{
		throw ShrubberyCreationForm::CannotExecute();
	}
	file << " _\n";
	file << "| |\n";
	file << "| |_ _ __ ___  ___\n";
	file << "| __| '__/ _ \/ _ \\n";
	file << "| |_| | |  __/  __/\n";
 	file << " \__|_|  \___|\___|\n";
	file.close();
}

const char* ShrubberyCreationForm::CannotExecute::what(void) const throw()
{
	return "Cannot execute Shrubbery creation";
}