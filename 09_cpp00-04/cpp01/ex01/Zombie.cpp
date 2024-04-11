#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{}

Zombie::Zombie(std::string name)
	: name(name)
{
	std::cout << '[' << name << "] create" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << '[' << this->name << "] remove" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}