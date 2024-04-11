#pragma once
#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *mWeapon;
	std::string mName;
public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack(void);
};

#endif