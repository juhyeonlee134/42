#pragma once
#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon weapon;
	std::string name;
public:
	HumanA(std::string name, std::string weaponType);
	~HumanA();
	void attack(void) const;
};

#endif