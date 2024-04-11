#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: mIsKeeper(false)
{
	this->setHP(100);
	this->setEP(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " create" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
	, mIsKeeper(false)
{
	this->setHP(100);
	this->setEP(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << name << " create" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& org)
	: ClapTrap(org)
{
	std::cout << "ScavTrap " << org.getName() << " copy" << std::endl;
	*this = org;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " remove" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->setName(org.getName());
	this->setHP(org.getHP());
	this->setEP(org.getEP());
	this->setAttackDamage(org.getAttackDamage());
	this->mIsKeeper = org.getIsKeeper();
	return *this;
}

bool ScavTrap::getIsKeeper(void) const
{
	return this->mIsKeeper;
}

void ScavTrap::setIsKeeper(const bool isKeeper)
{
	this->mIsKeeper = isKeeper;
}

void ScavTrap::attack(const std::string& target)
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
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEP(this->getEP() - 1);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
	this->mIsKeeper = true;
}
