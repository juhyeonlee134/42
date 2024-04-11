#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	Animal* j = new Dog();
	Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "-----------------------------------------" << std::endl;
	{
		Animal* animals[10];
		Brain dogBrain;
		Brain catBrain;

		std::cout << "\n* SET ANIMALS *" << std::endl;
		for (size_t index = 0; index < 100; index++)
		{
			dogBrain.setIdea("Bark Bark", index);
			catBrain.setIdea("Meow Meow", index);
		}
		for (size_t index = 0; index < 5; index++)
		{
			animals[index] = new Dog(dogBrain);
		}
		for (size_t index = 5; index < 10; index++)
		{
			animals[index] = new Cat(catBrain);
		}

		std::cout << "\n* CHECK DOG DEEP COPY *" << std::endl;
		{
			Dog* org = dynamic_cast<Dog*>(animals[0]);
			Dog* cpy = new Dog(*org);
			Brain& orgPtr = org->getBrain();
			Brain& cpyPtr = cpy->getBrain();
			std::cout << &orgPtr << " : " << orgPtr.getIdea(0) << std::endl;
			std::cout << &cpyPtr << " : " << cpyPtr.getIdea(0) << std::endl;
			orgPtr.setIdea("Meow Meow", 0);
			std::cout << orgPtr.getIdea(0) << " | " << cpyPtr.getIdea(0) << std::endl;
			cpyPtr.setIdea("Woo Woo", 0);
			std::cout << orgPtr.getIdea(0) << " | " << cpyPtr.getIdea(0) << std::endl;
			delete cpy;
		}
		std::cout << "\n* CHECK CAT DEEP COPY *" << std::endl;
		{
			Cat* org = dynamic_cast<Cat*>(animals[5]);
			Cat* cpy = new Cat(*org);
			Brain& orgPtr = org->getBrain();
			Brain& cpyPtr = cpy->getBrain();
			std::cout << &orgPtr << " : " << orgPtr.getIdea(0) << std::endl;
			std::cout << &cpyPtr << " : " << cpyPtr.getIdea(0) << std::endl;
			orgPtr.setIdea("Bark Bark", 0);
			std::cout << orgPtr.getIdea(0) << " | " << cpyPtr.getIdea(0) << std::endl;
			cpyPtr.setIdea("Woo Woo", 0);
			std::cout << orgPtr.getIdea(0) << " | " << cpyPtr.getIdea(0) << std::endl;
			delete cpy;
		}
		std::cout << "\n* DESTRUCTOR *" << std::endl;
		for (size_t index = 0; index < 10; index++)
		{
			delete animals[index];
		}
	}

	return 0;
}
