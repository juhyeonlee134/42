#include "Animal.hpp"
#include <iostream>

Animal::Animal()
	: type("")
{
	std::cout << "Animal " << this->type << " create" << std::endl;
}

Animal::Animal(std::string const& type)
	: type(type)
{
	std::cout << "Animal " << this->type << " create" << std::endl;
}

Animal::Animal(Animal const& org)
{
	std::cout << "Animal " << org.getType() << " copy" << std::endl;
	*this = org;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->type << " remove" << std::endl;
}

Animal& Animal::operator = (Animal const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.getType();
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::setType(std::string const type)
{
	this->type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "???" << std::endl;
}
