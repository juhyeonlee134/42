#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : protected Animal
{
public:
	Dog();
	Dog(Brain const& brain);
	Dog(Dog const& org);
	~Dog();
	Dog& operator = (Dog const& org);
	Brain& getBrain(void) const;
	void setBrain(Brain const& brain);
	void makeSound(void) const;
private:
	Brain* mBrain;
};

#endif
