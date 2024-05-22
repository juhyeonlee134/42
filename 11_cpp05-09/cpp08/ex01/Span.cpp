#include "Span.hpp"
#include <vector>
#include <stdexcept>
#include <cmath>

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

void Span::addNumber(int const num) throw(std::logic_error)
{
	if (this->mStored.size() == this->N)
	{
		throw std::logic_error("overflow");
	}
	this->mStored.push_back(num);
}

unsigned int Span::shortestSpan(void) const throw(std::logic_error)
{
	if (this->mStored.size() <= 1)
	{
		throw std::logic_error("No element to compare");
	}
	unsigned int span = 4294967295u;
	std::vector<int>::const_iterator i;
	for (i = this->mStored.begin(); i != this->mStored.end(); i++)
	{
		std::vector<int>::const_iterator j;
		for (j = i + 1; j != this->mStored.end(); j++)
		{
			long sub = *i - *j;
			unsigned int diff = std::abs(sub);
			if (span > diff)
			{
				span = diff;
			}
		}
	}
	return span;
}

unsigned int Span::longestSpan(void) const throw(std::logic_error)
{
	if (this->mStored.size() <= 1)
	{
		throw std::logic_error("No element to compare");
	}
	int max = -2147483648;
	int min = 2147483647;
	std::vector<int>::const_iterator it;
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
	long sub = max - min;
	unsigned int span = std::abs(sub);
	return span;
}