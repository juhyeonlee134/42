#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
	, mBrain(new Brain())
{
	std::cout << "Dog create" << std::endl;
}

Dog::Dog(Brain const& brain)
	: Animal("Dog")
	, mBrain(new Brain(brain))
{
	std::cout << "Dog create" << std::endl;
}

Dog::Dog(Dog const& org)
	: Animal(org)
{
	std::cout << "Dog copy" << std::endl;
	*this = org;
}

Dog::~Dog()
{
	delete this->mBrain;
	this->mBrain = NULL;
	std::cout << "Dog remove" << std::endl;
}

Dog& Dog::operator = (Dog const& org)
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

Brain& Dog::getBrain(void) const
{
	return *(this->mBrain);
}

void Dog::setBrain(Brain const& brain)
{
	if (this->mBrain != NULL)
	{
		delete this->mBrain;
	}
	this->mBrain = new Brain(brain);
}

void Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
