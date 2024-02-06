#include "Contact.hpp"
#include <cctype>
#include <iostream>

Contact::Contact()
{}

Contact::~Contact()
{}

void Contact::SetContact(void)
{
	this->mFirstName = getUserInput("Enter first name");
	this->mLastName = getUserInput("Enter last name");
	this->mNickname = getUserInput("Enter nickname");
	this->mPhoneNum = getUserInput("Enter phone number");
	this->mDarkestSecret = getUserInput("Enter darkest secret");
}

void Contact::PrintContact(void) const
{
	std::cout << "1. Frist name: " << this->mFirstName << std::endl;
	std::cout << "2. Last name: " << this->mLastName << std::endl;
	std::cout << "3. Nickname: " << this->mNickname << std::endl;
	std::cout << "4. Phone number: " << this->mPhoneNum << std::endl;
	std::cout << "5. Darkest secret: " << this->mDarkestSecret << std::endl;
}

std::string Contact::getFirstName(void) const
{
	if (this->mFirstName.length() <= 10)
	{
		return this->mFirstName;
	}
	return this->mFirstName.substr(0, 9) + '.';
}

std::string Contact::getLastName(void) const
{
	if (this->mLastName.length() <= 10)
	{
		return this->mLastName;
	}
	return this->mLastName.substr(0, 9) + '.';
}

std::string Contact::getNickname(void) const
{
	if (this->mNickname.length() <= 10)
	{
		return this->mNickname;
	}
	return this->mNickname.substr(0, 9) + '.';
}

bool isBlank(const std::string str)
{
	size_t blankCnt = 0;

	for (size_t index = 0; index < str.length(); index++)
	{
		if (std::iswblank(str[index]))
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

std::string getUserInput(const std::string message)
{
	std::string userInput;

	if (std::cin.eof())
	{
		throw std::invalid_argument("eof");
	}
	while (1)
	{
		std::cout << message << ": ";
		if (!std::getline(std::cin, userInput))
		{
			throw std::invalid_argument("eof");
		}
		std::cin.clear();
		if (!userInput.empty() && !isBlank(userInput))
		{
			break;
		}
	}
	return userInput;
}