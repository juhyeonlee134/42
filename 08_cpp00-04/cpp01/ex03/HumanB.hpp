#pragma once
#ifndef __HUMAN_B__
#define __HUMAN_B__

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon weapon;
	std::string name;
public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(const Weapon weapon);
	void attck(void) const;
};

#endif