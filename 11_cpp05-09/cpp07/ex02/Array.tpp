#pragma once
#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include "Array.hpp"
#include <exception>
#include <cstdlib>

template <typename T>
Array<T>::Array()
	: mArr(NULL)
	, mSize(0)
{}

template <typename T>
Array<T>::Array(unsigned int const n)
{
	if (n == 0)
	{
		this->mArr = NULL;
		this->mSize = 0;
	}
	else
	{
		this->mArr = new T[n];
		this->mSize = n;
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->mArr != NULL)
	{
		delete[] this->mArr;
	}
}

template<typename T>
Array<T>::Array(Array const & org)
{
	if (this == &org)
	{
		return;
	}
	if (org.size() == 0)
	{
		this->mSize = 0;
		this->mArr = NULL;
	}
	else
	{
		this->mSize = org.size();
		this->mArr = new T[org.size()];
		for (std::size_t index = 0; index < this->mSize; index++)
		{
			this->mArr[index] = org.mArr[index];
		}
	}
}

template<typename T>
Array<T> & Array<T>::operator = (Array const & org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mSize = org.size();
	if (this->mArr != NULL)
	{
		delete[] this->mArr;
	}
	this->mArr = new T[this->mSize];
	for (unsigned int index = 0; index < this->mSize; index++)
	{
		this->mArr[index] = org.mArr[index];
	}
	return *this;
}

template<typename T>
T & Array<T>::operator [] (unsigned int const index)
{
	if (index >= this->mSize)
	{
		throw std::exception();
	}
	return this->mArr[index];
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return this->mSize;
}

#endif