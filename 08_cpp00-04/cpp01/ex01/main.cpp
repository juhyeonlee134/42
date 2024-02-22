#include "Zombie.hpp"

int main(void)
{
	Zombie z1 = Zombie("zombie 1");
	z1.announce();

	Zombie *zHorde = z1.zombieHorde(10, "clone");
	for (int i = 0; i < 10; i++)
	{
		zHorde[i].announce();
	}
	delete[] zHorde;
	return 0;
}