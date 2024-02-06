#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, std::string weaponType)
{
	this->weapon = Weapon();
	this->name = name;
	this->weapon.setType(weaponType);
};

HumanA::~HumanA()
{};

void HumanA::attack(void) const
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}