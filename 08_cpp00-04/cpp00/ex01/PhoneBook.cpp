#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "------------ * PHONE BOOK * ------------" << std::endl;
	this->index = -1;
	this->endPoint = 0;
};

PhoneBook::~PhoneBook()
{
	std::cout << "----------------------------------------" << std::endl;
}

void PhoneBook::addContact(void)
{
	Contact newContact = Contact();

	newContact.setContact();
	this->endPoint = this->endPoint >= 8 ? 8 : this->endPoint + 1;
	this->index = (this->index + 1) % 8;
	this->contacts[this->index] = newContact;
}

void PhoneBook::searchContact(void) const
{
	int index;

	std::cout << "Enter index(1~8): ";
	std::cin >> index;
	if (index > 8 || index < 1)
	{
		std::cout << "Error: Invalid range" << std::endl;
	}
	else if (index - 1 >= (int)this->endPoint)
	{
		std::cout << "Error: Invalid index" << std::endl;
	}
	else
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << '|' << std::setw(10) << "index";
		std::cout << '|' << std::setw(10) << "first name";
		std::cout << '|' << std::setw(10) << "last name";
		std::cout << '|' << std::setw(10) << "nickname" << '|' << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << '|' << std::setw(10) << index;
		this->contacts[index - 1].printContact();
		std::cout << "---------------------------------------------" << std::endl;
	}
}

std::string getCommand(void)
{
	std::string command = "";

	std::cout << "Enter command(ADD, SEARCH, EXIT): ";
	while (std::getline(std::cin, command))
	{
		std::cin.clear();
		if (!command.empty() && !isBlank(command))
		{
			break;
		}
		std::cout << "Enter command(ADD, SEARCH, EXIt): ";
	}
	return command;
}
