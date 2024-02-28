#pragma once
#ifndef __ICE_H__
#define __ICE_H__

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice const& org);
    ~Ice();
    Ice& operator = (Ice const& org);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif