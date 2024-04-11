#include "ClapTrap.hpp"
#include <iostream>

static void printStat(const ClapTrap& clapTrap)
{
	std::cout << clapTrap.getName() << " : HP(" << clapTrap.getHP() << ") EP(" << clapTrap.getEP() <<") DM(" << clapTrap.getAttackDamage() << ')' << std::endl;
}

int main(void)
{
	std::cout << '\n' << "* CONSTRUCTOR *" << std::endl;
	ClapTrap noname;
	ClapTrap b("B");
	b.setAttackDamage(5);
	printStat(noname);
	printStat(b);

	std::cout << '\n' << "* COPY CONSTRUCTOR *" << std::endl;
	ClapTrap clone(b);
	printStat(clone);
	clone.setName("clone");
	printStat(clone);

	std::cout << '\n' << "* ATTACK *" << std::endl;
	noname.attack(b.getName());
	b.takeDamage(noname.getAttackDamage());
	b.attack(noname.getName());
	noname.takeDamage(b.getAttackDamage());
	clone.attack(noname.getName());
	noname.takeDamage(clone.getAttackDamage());
	printStat(noname);
	printStat(b);
	printStat(clone);
	noname.beRepaired(10);
	noname.attack(b.getName());

	std::cout << '\n' << "* ENERGY POINTS *" << std::endl;
	b.setEP(0);
	printStat(b);
	b.attack(clone.getName());
	b.beRepaired(10);

	std::cout << '\n' << "* DESTRUCTOR *" << std::endl;
	return 0;
}
