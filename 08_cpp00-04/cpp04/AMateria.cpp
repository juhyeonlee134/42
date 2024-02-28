#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
    : mType("")
{}

AMateria::AMateria(std::string const& type)
    :mType(type)
{}

AMateria::AMateria(AMateria const& org)
{
    *this = org;
}

AMateria::~AMateria()
{}

AMateria& AMateria::operator = (AMateria const& org)
{
    if (this == &org)
    {
        return *this;
    }
    this->mType = org.getType();
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->mType;
}

void AMateria::use(ICharacter& target)
{
    std::cout << this->mType << std::endl;
}
