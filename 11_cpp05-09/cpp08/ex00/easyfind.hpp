#pragma once
#ifndef __EASY_FIND_H__
#define __EASY_FIND_H__

#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T & t, int const n);

template<typename T>
typename T::iterator easyfind(T const & t, int const n);

#include "easyfind.tpp"

#endif