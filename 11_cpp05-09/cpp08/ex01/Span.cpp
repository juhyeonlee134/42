#include "Span.hpp"
#include <exception>

Span::Span()
	: N(0)
	, mLen(0)
{}

Span::Span(unsigned int const N)
	: N(N)
	, mLen(0)
{}

Span::Span(Span const & org)
{
	*this = org;
}

Span & Span::operator = (Span const & org)
{
	if (this == &org)
	{
		return *this;
	}
	this->N = org.N;
	this->mStored = org.mStored;
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int const num)
{
	if (mLen >= this->N)
	{
		throw std::exception();
	}
	this->mStored.push_back(num);
	this->mLen++;
}

unsigned int Span::shortestSpan(void) const
{
	if (this->mLen <= 1)
	{
		throw std::exception();
	}
}

unsigned int Span::longestSpan(void) const
{
	if (this->mLen <= 1)
	{
		throw std::exception();
	}
}