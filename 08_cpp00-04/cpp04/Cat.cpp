#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat create" << std::endl;
}

Cat::Cat(Cat const& org)
{
	std::cout << "Cat copy" << std::endl;
	*this = org;
}

Cat::~Cat()
{
	std::cout << "Cat remove" << std::endl;
}

Cat& Cat::operator = (Cat const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
