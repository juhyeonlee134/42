#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
	: ClapTrap("noname_clap_name")
	, ScavTrap("noname_clap_name")
	, FragTrap("noname_clap_name")
	, mName("noname")
{
	this->setHP(this->FragTrap::getHP());
	this->setEP(this->ScavTrap::getEP());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
	this->setIsKeeper(this->ScavTrap::getIsKeeper());
	this->setHighFive(this->FragTrap::getHighFive());
	std::cout << "DiamondTrap noname create" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name + "_clap_name")
	, FragTrap(name + "_clap_name")
	, mName(name)
{
	this->setHP(this->FragTrap::getHP());
	this->setEP(this->ScavTrap::getEP());
	this->setAttackDamage(this->FragTrap::getAttackDamage());
	this->setIsKeeper(this->ScavTrap::getIsKeeper());
	this->setHighFive(this->FragTrap::getHighFive());
	std::cout << "DiamondTrap " << name << " create" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& org)
	: ClapTrap(org)
	, ScavTrap(org)
	, FragTrap(org)
{
	std::cout << "DiamondTrap " << org.getDName() << " copy" << std::endl;
	*this = org;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamonTrap " << this->getDName() << " remove" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mName = org.getDName();
	return *this;
}

std::string DiamondTrap::getDName(void) const
{
	return this->mName;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "WHO AM I : The name of ClapTrap that " << this->mName << " has is " << this->getName() << std::endl;
}
