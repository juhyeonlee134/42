#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
	: mName(name), mWeapon(weapon)
{}

HumanA::~HumanA()
{};

void HumanA::attack(void) const
{
	std::cout << this->mName;
	std::cout << " attacks with their ";
	std::cout << this->mWeapon.getType() << std::endl;
}