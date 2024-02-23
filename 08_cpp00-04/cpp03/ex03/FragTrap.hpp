#pragma once
#ifndef __FRAG_TRAP_H__
#define __FRAG_TRAP_H__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& org);
	~FragTrap();
	FragTrap& operator = (const FragTrap& org);
	std::string getHighFive(void) const;
	void setHighFive(const std::string& highFive);
	void attack(const std::string& target);
	void highFivesGuys(void);
private:
	std::string mHighFive;
};

#endif
