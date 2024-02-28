#pragma once
#ifndef __WRONG_CAT_H__
#define __WRONG_CAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const& org);
	~WrongCat();
	WrongCat& operator = (WrongCat const& org);
	void makeSound(void) const;
};

#endif
