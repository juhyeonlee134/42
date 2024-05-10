#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	for (std::size_t cnt = 0; cnt < 10; cnt++)
	{
		Base creator;
		Base * base = creator.generate();
		creator.identify(base);
		Base & copy = *base;
		creator.identify(copy);
		delete base;
	}
	return 0;
}
