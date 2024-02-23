#include "ScavTrap.hpp"
#include <iostream>

static void printStat(const ClapTrap& clapTrap)
{
	std::cout << clapTrap.getName() << " : HP(" << clapTrap.getHP() << ") EP(" << clapTrap.getEP() <<") DM(" << clapTrap.getAttackDamage() << ')' << std::endl;
}

static void printStat(const ScavTrap& scavTrap)
{
	std::cout << scavTrap.getName() << " : HP(" << scavTrap.getHP() << ") EP(" << scavTrap.getEP() << ") DM(" << scavTrap.getAttackDamage() << ") GM(" << (scavTrap.getIsKeeper() ? "T" : "F") << ')' << std::endl;
}

int main(void)
{
	std::cout << '\n' << "* CONSTRUCTOR *" << std::endl;
	ClapTrap master("Master");
	ScavTrap noname;
	printStat(master);
	printStat(noname);

	std::cout << '\n' << "* COPY CONSTRUCTOR *" << std::endl;
	ScavTrap clone(noname);
	// ScavTrap clone(master); <-- error
	printStat(clone);
	clone.setName("clone");
	printStat(clone);

	std::cout << '\n' << "* MEMBER FUNCTIONS *" << std::endl;
	master.setAttackDamage(100);
	master.attack(noname.getName());
	noname.takeDamage(master.getAttackDamage());
	noname.beRepaired(100);
	noname.attack(master.getName());
	clone.guardGate();
	clone.beRepaired(100);
	printStat(master);
	printStat(noname);
	printStat(clone);

	std::cout << '\n' << "* DESTRUCTOR *" << std::endl;
	return 0;
}
