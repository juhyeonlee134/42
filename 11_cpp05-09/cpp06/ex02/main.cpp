#include "functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	for (std::size_t cnt = 0; cnt < 10; cnt++)
	{
		Base * base = generate();
		identify(base);
		Base & copy = *base;
		identify(copy);
		std::cout << '\n';
		delete base;
	}
	return 0;
}
