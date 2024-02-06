#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon();
	void setType(std::string type);
	std::string getType(void) const;
};

#endif