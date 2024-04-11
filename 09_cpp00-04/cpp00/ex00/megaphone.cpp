#include <iostream>
#include <string>
#include <cctype>

static void printToUpper(std::string str);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int index = 1; index < argc - 1; index++)
	{
		printToUpper(argv[index]);
		std::cout << ' ';
	}
	printToUpper(argv[argc - 1]);
	std::cout << std::endl;
	return 0;
}

static void printToUpper(std::string str)
{
	for (size_t index = 0; index < str.length(); index++)
	{
		str[index] = std::toupper(str[index]);
	}
	std::cout << str;
}