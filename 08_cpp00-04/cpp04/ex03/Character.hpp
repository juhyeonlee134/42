#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(std::string const& name);
	Character(Character const& org);
	~Character();
	Character& operator=(Character const& org);

	std::string const& getName(void) const;
	AMateria* getSlot(size_t const index) const;
	size_t getIndex(void) const;
	void setName(std::string const& name);


	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string mName;
	AMateria* mSlot[4];
	size_t mIndex;
};

#endif