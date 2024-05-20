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
	MutantStack<T>::iterator it(this->c.begin());
	return it;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	MutantStack<T>::iterator it(this->c.end());
	return it;
}

template <typename T>
MutantStack<T>::iterator::iterator()
	: std::deque<T>::iterator()
{}

template <typename T>
MutantStack<T>::iterator::iterator(typename std::deque<T>::iterator const & it)
	: std::deque<T>::iterator(it)
{}

template <typename T>
MutantStack<T>::iterator::iterator(iterator const & org)
	: std::deque<T>::iterator(org)
{
	*this = org;
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator = (iterator const & org)
{
	if (this != &org)
		this->it = org.it;
	return *this;
}

#endif