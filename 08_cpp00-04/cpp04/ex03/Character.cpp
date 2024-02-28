#include "Character.hpp"
#include <iostream>

Character::Character(std::string const& name)
	: mName(name)
	, mIndex(0)
{
	for (size_t index = 0; index < 4; index++)
	{
		this->mSlot[index] = NULL;
	}
}

Character::Character(Character const& org)
{
	*this = org;
}

Character::~Character()
{
	for (size_t index = 0; index < this->mIndex; index++)
	{
		delete this->mSlot[index];
	}
}

Character& Character::operator=(Character const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mName = org.getName();
	this->mIndex = org.getIndex();
	for (size_t index = 0; index < 4; index++)
	{
		AMateria* tmp = org.mSlot[index];
		if (this->mSlot[index])
		{
			delete this->mSlot[index];
		}
		this->mSlot[index] = tmp ? tmp->clone() : NULL;
	}
	return *this;
}

std::string const& Character::getName(void) const
{
	return this->mName;
}

AMateria* Character::getSlot(size_t const index) const
{
	return this->mSlot[index];
}

size_t Character::getIndex(void) const
{
	return this->mIndex;
}

void Character::setName(std::string const& name)
{
	this->mName = name;
}

void Character::equip(AMateria* m)
{
	if (this->mIndex == 4)
	{
		std::cout << "Slot is fulled" << std::endl;
		return;
	}
	this->mSlot[this->mIndex] = m->clone();
	this->mIndex++;
}

void Character::unequip(int idx)
{
	if (this->mIndex == 0)
	{
		std::cout << "Slot is empty" << std::endl;
		return;
	}
	this->mIndex--;
}

void Character::use(int idx, ICharacter& target)
{
	this->mSlot[idx]->use(target);
}
