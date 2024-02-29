#pragma once
#ifndef __A_MATERIA_H__
#define __A_MATERIA_H__

#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string mType;
public:
	AMateria(std::string const& type);
	AMateria();
	AMateria(AMateria const& org);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
