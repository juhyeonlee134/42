#include "DiamondTrap.hpp"
#include <iostream>

static void printStat(const DiamondTrap& diamondTrap)
{
	std::cout << diamondTrap.getDName() << " : HP(" << diamondTrap.getHP() << ") EP(" << diamondTrap.getEP() << ") DM(" << diamondTrap.getAttackDamage() << ") GM(" << (diamondTrap.getIsKeeper() ? "T" : "F") << ')' << std::endl;
}

int main(void)
{
	std::cout << '\n' << "* CONSTRUCTOR *" << std::endl;
	DiamondTrap noname;
	DiamondTrap monster("Monster");

	printStat(noname);
	printStat(monster);

	std::cout << '\n' << "* COPY CONSTRUCTOR *" << std::endl;
	DiamondTrap clone(monster);
	printStat(clone);

	std::cout << '\n' << "* MEMBER FUNCTIONS *" << std::endl;
	monster.whoAmI();
	noname.whoAmI();
	clone.whoAmI();

	monster.attack(noname.getDName());
	noname.ClapTrap::takeDamage(monster.getAttackDamage());
	printStat(monster);
	printStat(noname);
	noname.beRepaired(1); // <-- HP 10
	noname.attack(monster.getDName());
	monster.ClapTrap::takeDamage(noname.getAttackDamage());
	printStat(monster);
	printStat(noname);

	std::cout << '\n' << "* DESTRUCTOR *" << std::endl;
	return 0;
}
