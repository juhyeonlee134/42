#include <iostream>
#include <cctype>

static void printUpper(const char *str);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		printUpper(argv[i]);
	}
	std::cout<<std::endl;
	return 0;
}

static void printUpper(const char *str)
{
	while (*str)
	{
		std::cout<<(char)std::toupper(*str);
		str++;
	}
	std::cout<<' ';
}
