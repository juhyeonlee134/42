#pragma once
#ifndef __ITER_H__
#define __ITER_H__

#include <iostream>

template <typename T>
void iter(T const * const arr, int const len, void (*func)(T const &))
{
	if (arr == NULL || func == NULL || len <= 0)
	{
		return ;
	}
	for (int index = 0; index < len; index++)
	{
		func(arr[index]);
	}
}

template<typename T>
void iter(T * const arr, int const len, void (*func)(T &))
{
	if (arr == NULL || func == NULL || len <= 0)
	{
		return ;
	}
	for (int index = 0; index < len; index++)
	{
		func(arr[index]);
	}
}

// for test
template<typename T>
void print(T const & t)
{
	std::cout << t << '\n';
}

template<typename T>
void addTwo(T & t)
{
	t += 2;
}

#endif