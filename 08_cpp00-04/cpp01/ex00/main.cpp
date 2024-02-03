#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1 = Zombie("zombie 1");
	zombie1.announce();

	zombie1.randomChump("zombie 2");

	Zombie *zombie2 = zombie1.newZombie("zombie 3");
	zombie2->announce();

	zombie2->randomChump("zombie 4");

	delete zombie2;
	return 0;
}