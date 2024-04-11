#include "Animal.hpp"
#include <iostream>

Animal::Animal()
	: type("")
{
	std::cout << "Animal create" << std::endl;
}

Animal::Animal(std::string const& type)
	: type(type)
{
	std::cout << "Animal (" << type << ") create" << std::endl;
}

Animal::Animal(Animal const& org)
{
	std::cout << "Animal copy" << std::endl;
	*this = org;
}

Animal::~Animal()
{
	std::cout << "Animal remove" << std::endl;
}

Animal& Animal::operator = (Animal const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::setType(std::string const& type)
{
	this->type = type;
}