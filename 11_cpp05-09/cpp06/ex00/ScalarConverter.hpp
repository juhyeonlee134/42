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
	static void convert(char const * str);
};

#endif
