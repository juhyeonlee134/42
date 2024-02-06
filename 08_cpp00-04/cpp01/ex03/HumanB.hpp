#pragma once
#ifndef __HUMAN_B__
#define __HUMAN_B__

#include "Weapon.hpp"

class HumanB
{
private:
	std::string mName;
	Weapon *mWeapon;
public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	void attack(void) const;
};

#endif