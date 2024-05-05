#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->checkSignAndGrade(executor);
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file.is_open())
	{
		throw std::ios_base::failure("failed open file " + this->getTarget() + "_shrubbery");
	}
	file << " _" << '\n';
	file << "| |" << '\n';
	file << "| |_ _ __ ___  ___" << '\n';
	file << "| __| \'__/ _ \\/ _ \\" << '\n';
	file << "| |_| | |  __/  __/" << '\n';
 	file << " \\__|_|  \\___|\\___|" << '\n';
	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "", 145, 127)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & org)
	: AForm(org.getName(), org.getTarget(), org.getSignGrade(), org.getExecuteGrade())
{}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (ShrubberyCreationForm const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}
