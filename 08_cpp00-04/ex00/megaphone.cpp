#include <iostream>

static void printUpper(const char *str);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int index = 1; index < argc - 1; index++)
		{
			printUpper(argv[index]);
			std::cout << ' ';
		}
		printUpper(argv[argc - 1]);
		std::cout << std::endl;
	}
	return 0;
}

static void printUpper(const char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			std::cout << (char)(*str - ('a' - 'A'));
		}
		else
		{
			std::cout << *str;
		}
		str++;
	}
}
