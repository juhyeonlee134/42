#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : mName(name), mWeapon(NULL)
{}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon &weapon)
{
	this->mWeapon = &weapon;
}

void HumanB::attack(void) const
{
	std::cout << this->mName;
	std::cout << " attacks with their ";
	std::cout << (this->mWeapon ? this->mWeapon->getType() : "fist") << std::endl;
}