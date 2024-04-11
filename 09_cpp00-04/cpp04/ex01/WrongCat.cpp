#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
	: WrongAnimal("Cat")
{
	std::cout << "Wrong Cat create" << std::endl;
}

WrongCat::WrongCat(WrongCat const& org)
	: WrongAnimal(org)
{
	std::cout << "Wrong Cat copy" << std::endl;
	*this = org;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat remove" << std::endl;
}

WrongCat& WrongCat::operator = (WrongCat const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow" << std::endl;
}
