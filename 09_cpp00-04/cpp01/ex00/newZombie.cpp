#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name)
{
	Zombie *nZombie = new Zombie(name);
	return nZombie;
}