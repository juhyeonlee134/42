#include "Character.hpp"
#include <iostream>

Character::Character()
    : mSlotIndex(0)
    , mName("noname")
{
    for (size_t index = 0; index < 4; index++)
    {
        this->mSlot[index] = NULL;
    }
    std::cout << "noname" << std::endl;
}

Character::Character(std::string const& name)
    : mSlotIndex(0)
    , mName(name)
{
    for (size_t index = 0; index < 4; index++)
    {
        this->mSlot[index] = NULL;
    }
    std::cout << name << std::endl;
}

Character::Character(Character const& org)
{
    *this = org;
    std::cout << this->mName << std::endl;
}

Character::~Character()
{
    for (size_t index = 0; this->mSlot[index]; index++)
    {
        delete this->mSlot[index];
    }
}

Character& Character::operator = (Character const& org)
{
    if (this == &org)
    {
        return *this;
    }
    this->mSlotIndex = org.mSlotIndex;
    this->mName = org.mName;
    for(size_t index = 0; index < 4; index++)
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

size_t Character::getSlotIndex(void) const
{
    return this->mSlotIndex;
}

std::string const& Character::getName(void) const
{
    return this->mName;
}

AMateria* Character::getSlot(size_t const index) const
{
    return this->mSlot[index];
}

void Character::setName(std::string const& name)
{
    this->mName = name;
}

void Character::equip(AMateria* m)
{
    if (this->mSlotIndex >= 4)
    {
        std::cout << "Slot is full" << std::endl;
        return;
    }
    this->mSlot[this->mSlotIndex] = m->clone();
    this->mSlotIndex++;
}

void Character::unequip(int idx)
{
    if (this->mSlotIndex == 0)
    {
        std::cout << "Slot is already empty" << std::endl;
        return;
    }
    this->mSlotIndex--;
}

void Character::use(int idx, ICharacter& target)
{
    this->mSlot[idx]->use(target);
}