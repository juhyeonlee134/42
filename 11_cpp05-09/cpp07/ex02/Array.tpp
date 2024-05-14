#pragma once
#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include "Array.hpp"
#include <exception>

template<typename T>
Array<T>::Array(unsigned int const n)
{
	this->mArr = new T[n];
	this->mSize = n;
	for (unsigned int index = 0; index < n; index++)
	{
		this->mArr[index] = 0;
	}
}

template<typename T>
Array<T>::~Array()
{
	delete this->mArr;
}

template<typename T>
Array<T>::Array(Array const & org)
{
	*this = org;
}

template<typename T>
Array<T> & Array<T>::operator = (Array const & org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mSize = org.size();
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

template<typename T>
Array<T>::Array()
	: mArr(NULL)
	, mSize(0)
{}

#endif