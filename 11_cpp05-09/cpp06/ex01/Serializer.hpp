#pragma once
#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
public:
	Serializer();
	Serializer(Serializer const & org);
	~Serializer();
	Serializer & operator = (Serializer const & org);
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
private:
};

#endif
