#pragma once
#ifndef __ARRAY_H__
#define __ARRAY_H__

template<typename T>
class Array
{
public:
	Array(unsigned int const n);
	~Array();
	Array(Array const & org);
	Array & operator = (Array const & org);
	T & operator [] (unsigned int const index);
	unsigned int size(void) const;
private:
	T * mArr;
	unsigned int mSize;
	Array();
};

#include "Array.tpp"

#endif