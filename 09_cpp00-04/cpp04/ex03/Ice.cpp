#include "ICharacter.hpp"
#include "Ice.hpp"
#include <iostream>

Ice::Ice()
	: AMateria("ice")
{}

Ice::Ice(Ice const& org)
	: AMateria(org)
{
	*this = org;
}

Ice::~Ice()
{}

Ice& Ice::operator=(Ice const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mType = org.getType();
	return *this;
}

AMateria* Ice::clone(void) const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
