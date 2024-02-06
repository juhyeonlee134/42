#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{}

void HumanB::setWeapon(const Weapon weapon)
{
	this->weapon = weapon;
}

void HumanB::attck(void) const
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}