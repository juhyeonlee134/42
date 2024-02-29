#include "ICharacter.hpp"
#include "Cure.hpp"
#include <iostream>

Cure::Cure()
    : AMateria("cure")
{}

Cure::Cure(Cure const& org)
    : AMateria(org)
{
    *this = org;
}

Cure::~Cure()
{}

Cure& Cure::operator=(Cure const& org)
{
    if (this == &org)
    {
        return *this;
    }
    this->mType = org.getType();
    return *this;
}

AMateria* Cure::clone(void) const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}