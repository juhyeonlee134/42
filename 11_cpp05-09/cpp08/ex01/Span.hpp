#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <vector>
#include <set>
#include <stdexcept>
#include <typeinfo>

class Span
{
public:
	Span();
	Span(unsigned int const N);
	Span(Span const & org);
	~Span();
	Span & operator = (Span const & org);
	void addNumber(int const num);
	template <typename C>
	void fillRange(typename C::iterator const & start, typename C::iterator const & end)
	{
		typename C::iterator it;
		for (it = start; it != end; it++)
		{
			if (typeid(*it) != typeid(int))
			{
				throw std::logic_error("is not int");
			}
		}
		if (this->mStored.size() + std::distance(start, end) > this->N)
		{
			throw std::logic_error("overflow");
		}
		for (it = start; it != end; it++)
		{
			this->mStored.push_back(*it);
		}
	}
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
private:
	unsigned int N;
	std::vector<int> mStored;
};

#endif