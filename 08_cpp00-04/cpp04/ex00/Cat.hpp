#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat const& org);
	~Cat();
	Cat& operator = (Cat const& org);
	void makeSound(void) const;
};

#endif
