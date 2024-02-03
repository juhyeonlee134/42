#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie zombie = Zombie("zombie");
	zombie.announce();
	std::cout << std::endl;

	Zombie *zombies = zombie.zombieHorde(10, "zombies");
	for (size_t index = 0; index < 10; index++)
	{
		zombies[index].announce();
	}
	delete[] zombies;
	std::cout << std::endl;

	zombies = zombie.zombieHorde(100, "many zombies");
	for (size_t index = 0; index < 100; index++)
	{
		zombies[index].announce();
	}
	delete[] zombies;
	std::cout << std::endl;

	return 0;
}