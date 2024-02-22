#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	Fixed f1;
	Fixed f2;

	f1.setRawBits(-1);
	std::cout << f1.getRawBits() << std::endl;
	std::cout << f2.getRawBits() << std::endl;

	f2.setRawBits(1);
	std::cout << f1.getRawBits() << std::endl;
	std::cout << f2.getRawBits() << std::endl;

	return 0;
}
