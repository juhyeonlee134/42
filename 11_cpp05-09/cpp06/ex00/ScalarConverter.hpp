#pragma once
#ifndef __SCALAR_CONVERTER_H__
#define __SCALAR_CONVERTER_H__

#include <string>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & org);
	~ScalarConverter();
	ScalarConverter & operator = (ScalarConverter const & org);
	void convert(char const * str);
private:
	static double toDouble(std::string const str);
	static void skipNumber(std::string const str, std::size_t & index);
	static void printCharactor(double const num);
	static void printInt(double const num);
	static void printFloat(double const num);
	static void printDouble(double const num);
};

#endif
