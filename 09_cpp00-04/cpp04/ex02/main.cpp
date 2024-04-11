#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	Dog* dog = new Dog();
	Cat* cat = new Cat();

	std::cout << "\n-------------------------------" << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << "-------------------------------\n" << std::endl;

	delete dog;
	delete cat;

	// Animal* animal = new Dog();
	// delete animal;

	return 0;
}
