#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <ios>

int main(void)
{
	Data data;
	data.c = 'A';
	data.z = 10;
	data.r = 3.14f;
	std::cout << "origin pointer : " << &data << '\n';

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "convert1 : " << ptr << '\n';
	std::cout << "convert1 hex : " << std::hex << ptr << '\n';
	Data * p = Serializer::deserialize(ptr);
	std::cout << "convert2 : " << p << '\n';
	return 0;
}
