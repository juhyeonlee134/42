#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	Base creator;
	Base * base = creator.generate();
	creator.identify(base);
	Base & copy = *base;
	creator.identify(copy);
	return 0;
}
