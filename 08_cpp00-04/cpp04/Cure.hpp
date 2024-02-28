#pragma once
#ifndef __CURE_H__
#define __CURE_H__

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const& org);
    ~Cure();
    Cure& operator=(Cure const& org);
    AMateria* clone(void) const;
    void use(ICharacter& target);
};

#endif