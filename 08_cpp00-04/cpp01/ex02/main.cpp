#include <iostream>
#include <iomanip>
#include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << std::left << std::setw(16) << "string's address" << ": " << std::hex << &string << std::endl;
	std::cout << std::left << std::setw(16) << "stringPTR" << ": " << std::hex << &stringPTR << std::endl;
	std::cout << std::left << std::setw(16) << "stringREF" << ": " << std::hex << &stringREF << std::endl << std::endl;

	std::cout << std::left << std::setw(16) << "string's value" << ": " << string << std::endl;
	std::cout << std::left << std::setw(16) << "stringPTR" << ": " << stringPTR << std::endl;
	std::cout << std::left << std::setw(16) << "stringREF" << ": " << stringREF << std::endl;

	return 0;
}