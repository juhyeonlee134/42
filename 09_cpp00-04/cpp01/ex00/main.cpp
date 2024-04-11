#include "Zombie.hpp"

int main(void)
{
	Zombie z1 = Zombie("zombie 1");
	z1.announce();

	z1.randomChump("zombie 2");

	Zombie *z2 = z1.newZombie("zombie 3");
	z2->announce();
	delete z2;
	return 0;
}