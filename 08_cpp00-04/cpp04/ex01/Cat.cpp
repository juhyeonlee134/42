#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat")
	, mBrain(new Brain())
{
	std::cout << "Cat create" << std::endl;
}

Cat::Cat(Brain const& brain)
	: Animal("Cat")
	, mBrain(new Brain(brain))
{
	std::cout << "Cat create" << std::endl;
}

Cat::Cat(Cat const& org)
	: Animal(org)
{
	std::cout << "Cat copy" << std::endl;
	*this = org;
}

Cat::~Cat()
{
	delete this->mBrain;
	std::cout << "Cat remove" << std::endl;
}

Cat& Cat::operator = (Cat const& org)
{
	if (this == &org)
	{
		return *this;
	}
	this->type = org.type;
	delete this->mBrain;
	this->mBrain = new Brain(org.getBrain());
	return *this;
}

Brain& Cat::getBrain(void) const
{
	return *(this->mBrain);
}

void Cat::setBrain(Brain const& brain)
{
	if (this->mBrain != NULL)
	{
		delete this->mBrain;
	}
	this->mBrain = new Brain(brain);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
