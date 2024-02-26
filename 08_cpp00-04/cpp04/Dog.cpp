#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog create" << std::endl;
}

Dog::Dog(Dog const& org)
{
	std::cout << "Dog copy" << std::endl;
	*this = org;
}

Dog::~Dog()
{
	std::cout << "Dog remove" << std::endl;
}

Dog& Dog::operator = (Dog const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
