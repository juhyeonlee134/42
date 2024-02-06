#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attck();
		jim.setWeapon(club);
		jim.attck();
		club.setType("some other of club");
		jim.attck();
	}
	return 0;
}