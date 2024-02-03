#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNum;
	std::string secret;
public:
	Contact();
	~Contact();
	void setContact(void);
	void printContact(void) const;
};

void printString(const std::string str);
bool isBlank(const std::string str);
std::string getUserInput(const std::string type);

#endif
