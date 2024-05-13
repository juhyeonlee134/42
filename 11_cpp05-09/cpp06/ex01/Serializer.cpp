#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const & org)
{
	*this = org;
}

Serializer::~Serializer()
{}

Serializer & Serializer::operator = (Serializer const & org)
{
	if (this == &org)
	{
		return *this;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
