#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : protected Animal
{
public:
	Cat();
	Cat(Brain const& brain);
	Cat(Cat const& org);
	~Cat();
	Cat& operator = (Cat const& org);
	Brain& getBrain(void) const;
	void setBrain(Brain const& brain);
	void makeSound(void) const;
private:
	Brain* mBrain;
};

#endif
