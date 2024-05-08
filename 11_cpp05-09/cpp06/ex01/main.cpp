#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main(void)
{
	Data data;
	data.c = 'A';
	data.z = 10;
	data.r = 3.14f;
	std::cout << "origin pointer : " << &data << '\n';

	Serializer serializer;
	uintptr_t ptr = serializer.serialize(&data);
	std::cout << "convert1 : " << ptr << '\n';
	std::cout << "convert1 hex : " << std::hex << ptr << '\n';
	Data * p = serializer.deserialize(ptr);
	std::cout << "convert2 : " << p << '\n';
	return 0;
}
