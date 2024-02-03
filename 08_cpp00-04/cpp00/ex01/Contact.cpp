#include "Contact.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

void Contact::setContact(void)
{
	this->firstName = getUserInput("first name");
	if (this->firstName.empty())
	{
		std::cout << std::endl;
		return;
	}
	this->lastName = getUserInput("last name");
	if (this->lastName.empty())
	{
		std::cout << std::endl;
		return;
	}
	this->nickname = getUserInput("nickname");
	if (this->nickname.empty())
	{
		std::cout << std::endl;
		return;
	}
	this->phoneNum = getUserInput("phone number");
	if (this->phoneNum.empty())
	{
		std::cout << std::endl;
		return;
	}
	this->secret = getUserInput("darkest secret");
	if (this->secret.empty())
	{
		std::cout << std::endl;
		return;
	}
}

void Contact::printContact(void) const
{
	printString(this->firstName);
	printString(this->lastName);
	printString(this->nickname);
	std::cout << '|' << std::endl;
}

void printString(const std::string str)
{
	if (str.length() > 10)
	{
		std::cout << '|' << str.substr(0, 9) << '.';
	}
	else
	{
		std::cout << '|' << std::setw(10) << str;
	}
}

bool isBlank(const std::string str)
{
	size_t blankCnt;

	blankCnt = 0;
	for (size_t index = 0; index < str.length(); index++)
	{
		if (str[index] == ' ' || str[index] == '\t' || str[index] == '\n' || str[index] == '\r')
		{
			blankCnt++;
		}
	}
	if (blankCnt == str.length())
	{
		return true;
	}
	return false;
}

std::string getUserInput(const std::string type)
{
	std::string userInput = "";

	std::cout << "Enter " << type << ": ";
	while (std::getline(std::cin, userInput))
	{
		std::cin.clear();
		if (!userInput.empty() && !isBlank(userInput))
		{
			break;
		}
		std::cout << "Enter " << type << ": ";
	}
	return userInput;
}