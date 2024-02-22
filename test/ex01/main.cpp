#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	// Fixed a;
	// Fixed const b(10);
	// Fixed const c(-42.42f);
	// Fixed const d(b);

	// a = Fixed(1234.4321f);

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;


	std::cout << "---------------------------------------------------" << std::endl;

	Fixed const f1(0);
	Fixed const f2(0.0f);
	Fixed const f3(0.1f);
	std::cout << "0 is " << f1 << std::endl;
	std::cout << "0.0f is " << f2 << std::endl;
	std::cout << "0.1f is " << f3 << std::endl;

	Fixed maxFixed;
	Fixed minFixed;
	Fixed const infFixed(10.0f / 0);
	Fixed const nanFixed(0.0f / 0.0f);

	maxFixed.setRawBits(0xFFFFFFFF);
	minFixed.setRawBits(0x1);

	std::cout << "maximum is " << maxFixed << std::endl;
	std::cout << "minimum is " << minFixed << std::endl;
	std::cout << "infinity is " << infFixed << std::endl;
	std::cout << "NaN is " << nanFixed << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;

	return 0;
}
