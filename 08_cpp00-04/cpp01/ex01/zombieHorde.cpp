#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N]();

	for (int index = 0; index < N; index++)
	{
		zombies[index].name = name;
	}
	return zombies;
}