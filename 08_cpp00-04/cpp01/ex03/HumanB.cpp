#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
	: mWeapon(NULL),
	mName(name)
{}

void HumanB::setWeapon(Weapon &weapon)
{
	this->mWeapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << this->mName << " attacks with their ";
	if (this->mWeapon == NULL)
	{
		std::cout << "fist" << std::endl;
	}
	else
	{
		std::cout << this->mWeapon->getType() << std::endl;
	}
}