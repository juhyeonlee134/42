#pragma once
#ifndef __EASY_FIND_TPP__
#define __EASY_FIND_TPP__

#include <iterator>
#include <exception>

template<typename T>
bool easyfind(T & t, int const n)
{
	typename T::iterator it = find(t.begin(), t.end(), n);
	if (it == t.end())
	{
		throw std::exception();
	}
	return true;
}

#endif