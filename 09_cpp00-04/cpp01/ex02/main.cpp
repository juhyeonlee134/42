#include <iostream>
#include <string>

int main(void)
{
	std::string stringORG = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringORG;
	std::string &stringREF = stringORG;

	std::cout << "[stringORG]'s address: " << &stringORG << std::endl;
	std::cout << "[stringPTR]'s address: " << &stringPTR << std::endl;
	std::cout << "[stringREF]'s address: " << &stringREF << std::endl;

	std::cout << "[stringORG]'s value: " << stringORG << std::endl;
	std::cout << "[stringPTR]'s value: " << stringPTR << std::endl;
	std::cout << "[stringREF]'s value: " << stringREF << std::endl;

	return 0;
}
