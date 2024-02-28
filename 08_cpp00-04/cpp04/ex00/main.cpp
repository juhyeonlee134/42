#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	// std::cout << "-------------------------------------------------" << std::endl;

	// WrongAnimal* wrongMeta = new WrongAnimal();
	// WrongAnimal* k = new WrongCat();
	// WrongCat* l = new WrongCat();

	// std::cout << k->getType() << " " << std::endl;
	// std::cout << l->getType() << " " << std::endl;
	// wrongMeta->makeSound();
	// k->makeSound();
	// l->makeSound();

	/* memory leak! */
	// delete wrongMeta;
	// delete k;
	// std::cout << "-------------------------------------------------" << std::endl;
	// delete l;

	std::cout << "-------------------------------------------------" << std::endl;

	Animal* animal = new Animal();
	WrongAnimal* wrongAnimal = new WrongAnimal();
	Dog* dog = new Dog();
	Cat* cat = new Cat();
	WrongCat* wrongCat = new WrongCat();

	std::cout << sizeof(*animal) << ' ' << sizeof(*wrongAnimal) << std::endl;
	std::cout << sizeof(*cat) << ' ' << sizeof(*wrongCat) << std::endl;
	std::cout << sizeof(*dog) << std::endl;

	delete animal;
	delete wrongAnimal;
	delete dog;
	delete cat;
	delete wrongCat;

	return 0;
}
