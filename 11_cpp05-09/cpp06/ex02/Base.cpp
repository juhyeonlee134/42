#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base()
{}

Base * Base::generate(void)
{
	Base * ret;
	std::srand(time(NULL));
	int randNum = std::rand() % 3;
	switch(randNum)
	{
		case 0 :
			ret = new A();
			break;
		case 1 :
			ret = new B();
			break;
		case 2 :
			ret = new C();
			break;
	}
	return ret;
}

void Base::identify(Base * p)
{
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "This is A\n";
	}
	else if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "This is B\n";
	}
	else if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "This is C\n";
	}
}

void Base::identify(Base & p)
{
	try
	{
		A & testA = dynamic_cast<A &>(p);
		std::cout << "addr : " << &testA << '\n';
		std::cout << "This is A\n";
	}
	catch (std::exception const & e)
	{}
	try
	{
		B & testB = dynamic_cast<B &>(p);
		std::cout << "addr : " << &testB << '\n';
		std::cout << "This is B\n";
	}
	catch(const std::exception& e)
	{}
	try
	{
		C & testC = dynamic_cast<C &>(p);
		std::cout << "addr : " << &testC << '\n';
		std::cout << "This is C\n";
	}
	catch(const std::exception& e)
	{}
}