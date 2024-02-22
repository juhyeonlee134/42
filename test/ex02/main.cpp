#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	// Fixed a;
	// Fixed const b(Fixed(5.05f) * Fixed(2));

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;


	std::cout << "-----------------------------------" << std::endl;

	Fixed f1;
	Fixed f2;
	Fixed f3(1.0f);
	Fixed zero(0);
	Fixed nan;

	// nan = zero / f3;
	nan = f3 / zero;
	std::cout << zero-- << std::endl;
	std::cout << --zero << std::endl;
	std::cout << zero-- << std::endl;
	std::cout << zero << std::endl;
	// f1++;
	// f2++;
	// f2++;
	// std::cout << f1 << " < " << f2 << (f1 < f2 ? " : true" : " : false") << std::endl;
	// std::cout << f1 << " > " << f2 << (f1 > f2 ? " : true" : " : false") << std::endl;

	// Fixed f3(10.015011f);
	// Fixed f4(10.015019f);
	// std::cout << f3 << " < " << f4 << (f3 < f4 ? " : true" : " : false") << std::endl;
	// std::cout << f3 << " > " << f4 << (f3 > f4 ? " : true" : " : false") << std::endl;
	// std::cout << f3 << " <= " << f4 << (f3 <= f4 ? " : true" : " : false") << std::endl;
	// std::cout << f3 << " >= " << f4 << (f3 >= f4 ? " : true" : " : false") << std::endl;
	// std::cout << f3 << " == " << f4 << (f3 == f4 ? " : true" : " : false") << std::endl;

	// std::cout << "-----------------------------------" << std::endl;

	return 0;
}
