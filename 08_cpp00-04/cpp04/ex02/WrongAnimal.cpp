#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
	: type("")
{
	std::cout << "Wrong Animal create" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const& type)
	: type(type)
{
	std::cout << "Wrong Animal (" << type << ") create" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& org)
{
	std::cout << "Wrong Animal copy" << std::endl;
	*this = org;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal remove" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (WrongAnimal const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.type;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::setType(std::string const& type)
{
	this->type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I'm Wrong Animal" << std::endl;
}
