#pragma once
#ifndef __Character_H__
#define __CAHRACTOR_H__

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(std::string const& mName);
    Character(Character const& org);
    ~Character();
    Character& operator = (Character const& org);
    size_t getSlotIndex(void) const;
    std::string const& getName(void) const;
    AMateria* getSlot(size_t const index) const;
    void setName(std::string const& name);
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
private:
    size_t mSlotIndex;
    std::string mName;
    AMateria* mSlot[4];
    // unequip은?
};

#endif