#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <vector>

class Span
{
public:
	Span(unsigned int const N);
	Span(Span const & org);
	Span & operator = (Span const & org);
	~Span();
	void addNumber(int const num);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
private:
	unsigned int N;
	unsigned int mLen;
	std::vector<int> mStored;
	Span();
};

#endif