#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon weapon)
	: name(name), weapon(weapon)
{}

HumanA::~HumanA()
{};

void HumanA::attack(void) const
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}