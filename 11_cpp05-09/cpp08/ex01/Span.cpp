#include "Span.hpp"
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>

Span::Span()
	: N(0)
{
	this->mStored.clear();
}

Span::Span(unsigned int const N)
	: N(N)
{
	this->mStored.clear();
}

Span::Span(Span const & org)
{
	if (this == &org)
	{
		return;
	}
	this->N = org.N;
	this->mStored = org.mStored;
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
	if (this->mStored.size() == this->N)
	{
		throw std::logic_error("overflow");
	}
	this->mStored.push_back(num);
}

unsigned int Span::shortestSpan(void)
{
	if (this->mStored.size() <= 1)
	{
		throw std::logic_error("No element to compare");
	}
	if (this->mStored.size() == 2)
	{
		throw std::logic_error("Not found shortest span");
	}
	Span buff(*this);
	std::sort(this->mStored.begin(), this->mStored.end());
	unsigned int span = 4294967295u;
	for (std::size_t index = 1; index < this->mStored.size(); index++)
	{
		long sub = static_cast<long>(this->mStored[index - 1]) - static_cast<long>(this->mStored[index]);
		unsigned int diff = std::abs(sub);
		if (span > diff)
		{
			span = diff;
		}
	}
	return span;
}

unsigned int Span::longestSpan(void)
{
	if (this->mStored.size() <= 1)
	{
		throw std::logic_error("No element to compare");
	}
	if (this->mStored.size() == 2)
	{
		throw std::logic_error("Not found longest span");
	}
	int max = -2147483648;
	int min = 2147483647;
	std::vector<int>::iterator it;
	for (it = this->mStored.begin(); it != this->mStored.end(); it++)
	{
		if (max < *it)
		{
			max = *it;
		}
		if (min > *it)
		{
			min = *it;
		}
	}
	long sub = static_cast<long>(max) - static_cast<long>(min);
	unsigned int span = std::abs(sub);
	return span;
}