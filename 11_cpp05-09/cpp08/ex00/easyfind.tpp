#pragma once
#ifndef __EASY_FIND_TPP__
#define __EASY_FIND_TPP__

#include <iterator>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T & t, int const n)
{
	typename T::iterator it = find(t.begin(), t.end(), n);
	if (it == t.end())
	{
		throw std::logic_error("Element is not found");
	}
	return it;
}

template <typename T>
typename T::iterator easyfind(T const & t, int const n)
{
	typename T::const_iterator it = find(t.begin(), t.end(), n);
	if (it == t.end())
	{
		throw std::logic_error("Element is not found");
	}
	return it;
}

#endif