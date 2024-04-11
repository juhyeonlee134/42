#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

void PhoneBook::preview(void) const
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << '|' << std::setw(10) << "index";
	std::cout << '|' << std::setw(10) << "first name";
	std::cout << '|' << std::setw(10) << "last name";
	std::cout << '|' << std::setw(10) << "nickname" << '|' << std::endl;
	for (size_t index = 0; index < this->endPoint; index++)
	{
		std::cout << '|' << std::setw(10) << index + 1;
		std::cout << '|' << std::setw(10) << this->contacts[index].getFirstName();
		std::cout << '|' << std::setw(10) << this->contacts[index].getLastName();
		std::cout << '|' << std::setw(10) << this->contacts[index].getNickname() << '|' << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

int PhoneBook::getIndex(void) const
{
	int index;
	std::string userInput;

	if (std::cin.eof())
	{
		throw std::invalid_argument("eof");
	}
	while (1)
	{
		userInput = getUserInput("Enter index (1 ~ 8)");
		std::stringstream toNum(userInput);
		if (toNum >> index)
		{
			break ;
		}
		if (toNum.fail())
		{
			std::cerr << "Error: is not number" << std::endl;
		}
	}
	return index;
}

PhoneBook::PhoneBook()
{
	std::cout << "-------------- * PHONE BOOK * --------------" << std::endl;
	this->index = 0;
	this->endPoint = 0;
};

PhoneBook::~PhoneBook()
{
	std::cout << std::endl << "--------------------------------------------" << std::endl;
}

void PhoneBook::Add(void)
{
	this->contacts[this->index].SetContact();
	this->index = (this->index + 1) % 8;
	this->endPoint = this->endPoint >= 8 ? 8 : this->endPoint + 1;
}

void PhoneBook::Search(void) const
{
	int index;

	preview();
	index = getIndex();
	index--;
	if (index < (int)this->endPoint && index >= 0)
	{
		this->contacts[index].PrintContact();
	}
	else
	{
		std::cerr << "Error: invalid range" << std::endl;
	}
}
