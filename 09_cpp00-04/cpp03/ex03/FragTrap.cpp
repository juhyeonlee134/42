#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: mHighFive("HIGH FIVVVVVE")
{
	this->setHP(100);
	this->setEP(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap noname create" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
	, mHighFive("HIGH FIVVVVVE")
{
	this->setHP(100);
	this->setEP(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << name << " create" << std::endl;
}

FragTrap::FragTrap(const FragTrap& org)
	: ClapTrap(org)
{
	std::cout << "FragTrap " << org.getName() << " copy" << std::endl;
	*this = org;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->getName() << " remove" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->setName(org.getName());
	this->setHP(org.getHP());
	this->setEP(org.getEP());
	this->setAttackDamage(org.getAttackDamage());
	this->mHighFive = org.getHighFive();
	return *this;
}

std::string FragTrap::getHighFive(void) const
{
	return this->mHighFive;
}

void FragTrap::setHighFive(const std::string& highFive)
{
	this->mHighFive = highFive;
}

void FragTrap::attack(const std::string& target)
{
	if (this->getHP() == 0)
	{
		std::cout << this->getName() << " is already dead" << std::endl;
		return;
	}
	if (this->getEP() == 0)
	{
		std::cout << this->getName() << " have no more energy" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEP(this->getEP() - 1);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "SacvTrap " << this->getName() << " positive high fives : " << this->mHighFive << std::endl;
}
