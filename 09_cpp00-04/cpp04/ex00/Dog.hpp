#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog const& org);
	~Dog();
	Dog& operator = (Dog const& org);
	void makeSound(void) const;
};

#endif
