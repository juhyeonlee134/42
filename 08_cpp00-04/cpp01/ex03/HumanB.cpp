#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attck(void) const
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << (this->weapon ? this->weapon->getType() : "fist") << std::endl;
}