#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	char ch1 = 'A';
	char ch2 = 'A';
	::swap(ch1, ch2);
	std::cout << ch1 << ' ' << ch2 << '\n';
	std::cout << "min : " << ::min(ch1, ch2) << '\n';
	std::cout << "max : " << ::max(ch1, ch2) << '\n';

	float f1 = 3.145f;
	float f2 = 3.333f;
	::swap(f1, f2);
	std::cout << f1 << ' ' << f2 << '\n';
	std::cout << "min : " << ::min(f1, f2) << '\n';
	std::cout << "max : " << ::max(f1, f2) << '\n';

	double d1 = 10.101010f;
	double d2 = 10.10102f;
	::swap(d1, d2);
	std::cout << d1 << ' ' << d2 << '\n';
	std::cout << "min : " << ::min(d1, d2) << '\n';
	std::cout << "max : " << ::max(d1, d2) << '\n';

	// char str1[6] = "abcde";
	// char str2[4] = "abc";
	// ::swap(str1, str2);
	// std::cout << str1 << ' ' << str2 << '\n';
	// std::cout << "min : " << ::min(str1 ,str2) << '\n';
	// std::cout << "max : " << ::max(str1, str2) << '\n';
	return 0;
}