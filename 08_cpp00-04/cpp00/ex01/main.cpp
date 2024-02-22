#include "PhoneBook.hpp"
#include <iostream>

static bool executeCommand(PhoneBook &phoneBook);

int main(void)
{
	PhoneBook phoneBook = PhoneBook();
	while (executeCommand(phoneBook));
	return 0;
}

static bool executeCommand(PhoneBook &phoneBook)
{
	std::string userInput;

	try
	{
		userInput = getUserInput("Enter command (ADD, SEARCH, EXIT)");
		if (userInput == "ADD")
		{
			phoneBook.Add();
		}
		else if (userInput == "SEARCH")
		{
			phoneBook.Search();
		}
		else if (userInput == "EXIT")
		{
			return false;
		}
		else
		{
			std::cerr << "Error: invalid command" << std::endl;
		}
	}
	catch(const std::invalid_argument& e)
	{
		return false;
	}
	return true;
}
