#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook = PhoneBook();
	std::string userInput;

	while (1)
	{
		userInput = getCommand();
		if (userInput.empty())
		{
			break;
		}
		if (userInput == "ADD")
		{
			phoneBook.addContact();
		}
		else if (userInput == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (userInput == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Error: Invalid command" << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
