#pragma once
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	int index;
	size_t endPoint;
	Contact contacts[8];
public:
	PhoneBook();
	~PhoneBook();
	void addContact(void);
	void searchContact(void) const;
};

std::string getCommand(void);

#endif
