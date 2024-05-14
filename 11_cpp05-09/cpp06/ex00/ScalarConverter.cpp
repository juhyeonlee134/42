#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>

static double toDouble(std::string const str);
static void skipNumber(std::string const str, std::size_t & index);
static void printCharactor(double const num);
static void printInt(double const num);
static void printFloat(double const num);
static void printDouble(double const num);

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const & org)
{
	*this = org;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter & ScalarConverter::operator = (ScalarConverter const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}

void ScalarConverter::convert(char const * str)
{
	double num = toDouble(str);
	if (std::isnan(num) || std::isinf(num))
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : " << static_cast<float>(num) << "f\n";
		std::cout << "double : " << num << '\n';
	}
	else
	{
		printCharactor(num);
		printInt(num);
		printFloat(num);
		printDouble(num);
	}
}

static double toDouble(std::string const str)
{
	if (str.size() == 0)
	{
		throw std::invalid_argument("invalid input");
	}
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		return static_cast<double>(str[0]);
	}
	double num = std::atof(str.c_str());
	std::size_t index;
	if (std::isnan(num) && (str == "nanf" || str == "nan"))
	{
		return num;
	}
	if (std::isinf(num) && (str == "inff" || str == "+inff" || str == "-inff" || str == "inf" || str == "+inf" || str == "-inf"))
	{
		return num;
	}
	skipNumber(str, index);
	if (index == str.length() || (index + 1 == str.length() && str[index] == 'f'))
	{
		return num;
	}
	throw std::invalid_argument("invalid input");
	return num;
}

static void skipNumber(std::string const str, std::size_t & index)
{
	index = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		index++;
	}
	while (std::isdigit(str[index]))
	{
		index++;
	}
	if (str[index] == '.')
	{
		index++;
		while (std::isdigit(str[index]))
		{
			index++;
		}
	}
}

static void printCharactor(double const num)
{
	int const ch = static_cast<int>(num);

	std::cout << "char : ";
	if (num > 255 || num < 0)
	{
		std::cout << "impossible\n";
	}
	else if (std::isprint(ch))
	{
		std::cout << '\'' << static_cast<char>(ch) << "\'\n";
	}
	else
	{
		std::cout << "Non printable\n";
	}
}

static void printInt(double const num)
{
	int const z = static_cast<int>(num);

	std::cout << "int : ";
	if (num > 2147483647.0 || num < -2147483648.0)
	{
		std::cout << "impossible\n";
	}
	else
	{
		std::cout << z << '\n';
	}
}

static void printFloat(double const num)
{
	float const fNum = static_cast<float>(num);

	std::cout << "float : " << fNum;
	if (num - static_cast<int>(num) == 0)
	{
		std::cout << ".0f\n";
	}
	else
	{
		std::cout << "f\n";
	}
}

static void printDouble(double const num)
{
	std::cout << "double : " << num;
	if (num - static_cast<int>(num) == 0)
	{
		std::cout << ".0";
	}
	std::cout << '\n';
}
