#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>

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
	if (std::isnan(num) && std::isinf(num))
	{
		std::cout << "char : impossible\n";
		std::cout << "int : impossible\n";
		std::cout << "float : " << static_cast<float>(num) << "f\n";
		std::cout << "double : " << num << '\n';
	}
	else
	{
		printCharactor(static_cast<char>(num));
		std::cout << "int : " << static_cast<int>(num) << '\n';
		printFloat(static_cast<float>(num));
		printDouble(num);
	}
}

double ScalarConverter::toDouble(std::string const str)
{
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

void ScalarConverter::skipNumber(std::string const str, std::size_t & index)
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

void ScalarConverter::printCharactor(int const ch)
{
	std::cout << "char : ";
	if (std::isprint(ch))
	{
		std::cout << '\'' << static_cast<char>(ch) << "\'\n";
	}
	else
	{
		std::cout << "Non printable\n";
	}
}

void ScalarConverter::printFloat(float const num)
{
	std::cout << "float : " << num;
	if (num - static_cast<int>(num) == 0)
	{
		std::cout << ".0f\n";
	}
	else
	{
		std::cout << "f\n";
	}
}

void ScalarConverter::printDouble(double const num)
{
	std::cout << "double : " << num;
	if (num - static_cast<int>(num) == 0)
	{
		std::cout << ".0";
	}
	std::cout << '\n';
}
