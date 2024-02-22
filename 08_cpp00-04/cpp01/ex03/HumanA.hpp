#pragma once
#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &mWeapon;
	std::string mName;
public:
	HumanA(std::string name, Weapon &weapon);
	void attack(void);
};

#endif