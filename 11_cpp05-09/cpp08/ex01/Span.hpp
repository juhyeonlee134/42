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
private:
	unsigned int const N;
	Span();
};

#endif