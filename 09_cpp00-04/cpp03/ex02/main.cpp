#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	ScavTrap human("Human");
	FragTrap noname;
	printStat(master);
	printStat(human);
	printStat(noname);

	std::cout << '\n' << "* COPY CONSTRUCTOR *" << std::endl;
	FragTrap clone(noname);
	printStat(clone);
	clone.setName("clone");
	printStat(clone);

	std::cout << '\n' << "* MEMBER FUNCTIONS *" << std::endl;
	noname.highFivesGuys();
	master.setAttackDamage(200);
	master.attack(noname.getName());
	noname.takeDamage(master.getAttackDamage());
	noname.beRepaired(100);
	noname.attack(master.getName());
	human.attack(clone.getName());
	clone.takeDamage(human.getAttackDamage());
	clone.beRepaired(10);
	clone.attack(human.getName());
	human.takeDamage(clone.getAttackDamage());
	printStat(master);
	printStat(human);
	printStat(noname);
	printStat(clone);
	clone.highFivesGuys();

	std::cout << '\n' << "* DESTRUCTOR *" << std::endl;
	return 0;
}
