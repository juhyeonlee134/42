#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string mFirstName;
	std::string mLastName;
	std::string mNickname;
	std::string mPhoneNum;
	std::string mDarkestSecret;
public:
	Contact();
	~Contact();
	void SetContact(void);
	void PrintContact(void) const;
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
};

bool isBlank(const std::string str);
std::string getUserInput(const std::string message);

#endif
