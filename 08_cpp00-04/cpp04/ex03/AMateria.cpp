#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
	: mType("")
{}

AMateria::AMateria(std::string const& type)
	: mType(type)
{}

AMateria::AMateria(AMateria const& org)
{
	*this = org;
}

AMateria::~AMateria()
{}

std::string const& AMateria::getType(void) const
{
	return this->mType;
}

void AMateria::use(ICharacter& target)
{
	std::cout << this->mType << std::endl;
}
