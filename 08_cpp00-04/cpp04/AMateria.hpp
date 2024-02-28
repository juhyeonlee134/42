#pragma once
#ifndef __A_MATERIA_H__
#define __A_MATERIA_H__

#include <string>

class ICharacter;

class AMateria
{
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria const& org);
    ~AMateria();
    AMateria& operator = (AMateria const& org);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
protected:
    ~AMateria();
    std::string mType;
};

#endif