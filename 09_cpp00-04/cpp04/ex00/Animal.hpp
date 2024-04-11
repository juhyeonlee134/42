#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

class Animal
{
public:
	Animal();
	Animal(std::string const& type);
	Animal(Animal const& org);
	virtual ~Animal();
	Animal& operator = (Animal const& org);
	std::string getType(void) const;
	void setType(std::string const& type);
	virtual void makeSound(void) const;
protected:
	std::string type;
};

#endif
