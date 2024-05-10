#pragma once
#ifndef __ITER_H__
#define __ITER_H__

#include <iostream>

template <typename T, typename F>
void iter(T const * const arr, std::size_t const len, void (*func)(F const &))
{
	if (arr == NULL || func == NULL)
	{
		return ;
	}
	for (std::size_t index = 0; index < len; index++)
	{
		func(arr[index]);
	}
}

template<typename T, typename F>
void iter(T * const arr, std::size_t const len, void (*func)(F &))
{
	if (arr == NULL || func == NULL)
	{
		return ;
	}
	for (std::size_t index = 0; index < len; index++)
	{
		func(arr[index]);
	}
}

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