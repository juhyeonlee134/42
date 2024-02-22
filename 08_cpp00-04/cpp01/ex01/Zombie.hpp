#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(std::string name);
	void announce(void);
	Zombie *zombieHorde(int N, std::string name);
};

#endif