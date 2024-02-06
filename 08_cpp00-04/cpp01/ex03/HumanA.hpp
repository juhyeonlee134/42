#pragma once
#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

#include "Weapon.hpp"

class HumanA
{
private:
	std::string mName;
	Weapon &mWeapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void) const;
};

#endif