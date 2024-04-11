#pragma once
#ifndef __WRONG_ANIMAL_H__
#define __WRONG_ANIMAL_H__

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string const& type);
	WrongAnimal(WrongAnimal const& org);
	~WrongAnimal();
	WrongAnimal& operator = (WrongAnimal const& org);
	std::string getType(void) const;
	void setType(std::string const& type);
	void makeSound(void) const;
protected:
	std::string type;
};

#endif
