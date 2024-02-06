#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{}

Zombie::Zombie(std::string name) : name(name)
{}

Zombie::~Zombie()
{
	std::cout << this->name << " destroy" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
