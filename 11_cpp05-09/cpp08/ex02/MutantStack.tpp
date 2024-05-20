#pragma once
#ifndef __MUTANTSTACK_TPP__
#define __MUTANTSTACK_TPP__

#include "MutantStack.hpp"
#include <stack>
#include <deque>

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & org)
	: std::stack<T>(org)
{
	*this = org;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T> & MutantStack<T>::operator = (MutantStack<T> const & org)
{
	if (this != &org)
		this->c = org.c;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

#endif