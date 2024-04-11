#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
	: mWeapon(weapon),
	mName(name)
{}

void HumanA::attack(void)
{
	std::cout << this->mName << " attacks with their " << this->mWeapon.getType() << std::endl;
}