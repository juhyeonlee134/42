#pragma once
#ifndef __SCAV_TRAP_H__
#define __SCAB_TRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public :
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& org);
	~ScavTrap();
	ScavTrap& operator = (const ScavTrap& org);
	bool getIsKeeper(void) const;
	void setIsKeeper(const bool isKeeper);
	void attack(const std::string& target);
	void guardGate(void);
private:
	bool mIsKeeper;
};

#endif
