#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie nZombie = Zombie(name);
	nZombie.announce();
}