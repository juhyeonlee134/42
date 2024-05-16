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
	void addNumber(int const num) throw(std::logic_error);
	template <typename C>
	void fillRange(typename C::iterator start, typename C::iterator end) throw(std::logic_error)
	{
		if (typeid(*start) != typeid(int) || typeid(*end) != typeid(int))
		{
			throw std::logic_error("is not int");
		}
		if (this->mStored.size() + std::distance(start, end) > this->N)
		{
			throw std::logic_error("overflow");
		}
		typename C::iterator it;
		for (it = start; it != end; it++)
		{
			this->mStored.push_back(*it);
		}
	}
	unsigned int shortestSpan(void) const throw(std::logic_error);
	unsigned int longestSpan(void) const throw(std::logic_error);
private:
	unsigned int N;
	std::vector<int> mStored;
};

#endif