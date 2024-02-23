#pragma once
#ifndef __CLAP_TRAP_H__
#define __CLAP_TRAP_H__

#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& org);
	~ClapTrap();
	ClapTrap& operator = (const ClapTrap& org);
	std::string getName(void) const;
	unsigned int getHP(void) const;
	unsigned int getEP(void) const;
	unsigned int getAttackDamage(void) const;
	void setName(const std::string& name);
	void setHP(const unsigned int hp);
	void setEP(const unsigned int ep);
	void setAttackDamage(const unsigned int attackDamage);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	std::string mName;
	unsigned int mHP;
	unsigned int mEP;
	unsigned int mAttackDamage;
};

#endif
