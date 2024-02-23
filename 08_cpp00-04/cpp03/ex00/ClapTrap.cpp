#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: mName("noname")
	, mHP(10)
	, mEP(10)
	, mAttackDamage(0)
{
	std::cout << "ClapTrap noname create" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: mName(name)
	, mHP(10)
	, mEP(10)
	, mAttackDamage(0)
{
	std::cout << "ClapTrap " << name << " create" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& org)
{
	std::cout << "ClapTrap " << org.getName() << " copy" << std::endl;
	*this = org;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->mName << " remove" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mName = org.getName();
	this->mHP = org.getHP();
	this->mEP = org.getEP();
	this->mAttackDamage = org.getAttackDamage();
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return this->mName;
}

unsigned int ClapTrap::getHP(void) const
{
	return this->mHP;
}

unsigned int ClapTrap::getEP(void) const
{
	return this->mEP;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->mAttackDamage;
}

void ClapTrap::setName(const std::string& name)
{
	this->mName = name;
}

void ClapTrap::setHP(const unsigned int hp)
{
	this->mHP = hp;
}

void ClapTrap::setEP(const unsigned int ep)
{
	this->mEP = ep;
}

void ClapTrap::setAttackDamage(const unsigned int damage)
{
	this->mAttackDamage = damage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->mHP == 0)
	{
		std::cout << this->mName << " is already dead" << std::endl;
		return;
	}
	if (this->mEP == 0)
	{
		std::cout << this->mName << " have no more energy" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->mName << " attacks " << target << ", causing " << this->mAttackDamage << " points of damage!" << std::endl;
	this->mEP--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->mHP == 0)
	{
		std::cout << this->mName << " is already dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->mName << " take " << amount << " damage!" << std::endl;
	if (this->mHP >= amount)
	{
		this->mHP -= amount;
	}
	else
	{
		this->mHP = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->mHP == 0)
	{
		std::cout << this->mName << " is already dead" << std::endl;
		return;
	}
	if (this->mEP == 0)
	{
		std::cout << this->mName << " have no more energy" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->mName << " is repaired " << amount << std::endl;
	this->mEP--;
	this->mHP += amount;
}
