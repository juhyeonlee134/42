#pragma once
#ifndef __DIAMOND_TRAP_H__
#define __DIAMOND_TRAP_H__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& org);
	~DiamondTrap();
	DiamondTrap& operator = (const DiamondTrap& org);
	std::string getDName(void) const;
	void attack(const std::string& target);
	void whoAmI(void);
private:
	std::string mName;
};

#endif
