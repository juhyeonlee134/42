#pragma once
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	size_t index;
	size_t endPoint;
	Contact contacts[8];
	void preview(void) const;
	int getIndex(void) const;
public:
	PhoneBook();
	~PhoneBook();
	void Add(void);
	void Search(void) const;
};

#endif
