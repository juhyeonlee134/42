#pragma once
#ifndef __MUTANT_STACK_TPP__
#define __MUTANT_STACK_TPP__

#include "MutantStack.hpp"
#include <stack>
#include <deque>

template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & org)
{
	*this = org;
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T> & MutantStack<T>::operator = (MutantStack<T> const & org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mStack = org.mStack;
	this->mDeque = this->mStack.c;
	return *this;
}

template <typename T>
T MutantStack<T>::top(void) const
{
	return this->mStack.top();
}

template <typename T>
bool MutantStack<T>::empty(void) const
{
	return this->mStack.empty();
}

template <typename T>
unsigned int MutantStack<T>::size(void) const
{
	return this->mStack.size();
}

template <typename T>
void MutantStack<T>::push(T const e)
{
	this->mStack.push(e);
}

template <typename T>
void MutantStack<T>::pop(void)
{
	this->mStack.pop();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) const
{
	typename std::deque<T> deq = this->mStack.c;
	return deq.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) const
{
	typename std::deque<T> deq = this->mStack.c;
	return deq.end();
}

template <typename T>
MutantStack<T>::iterator::iterator()
{}

template <typename T>
MutantStack<T>::iterator::iterator(typename std::deque<T>::iterator const itr)
	: mItr(itr)
{}

template <typename T>
MutantStack<T>::iterator::iterator(MutantStack<T>::iterator const & org)
{
	*this = org;
}

template <typename T>
MutantStack<T>::iterator::~iterator()
{}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator = (MutantStack<T>::iterator const & org)
{
	if (this == &org)
	{
		return *this;
	}
	this->mItr = org.mItr;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator ++ (void)
{
	this->mItr++;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator ++ (int tmp)
{
	MutantStack<T>::iterator ret = *this;
	tmp++;
	this->mItr++;
	return ret;
}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator -- (void)
{
	this->mItr--;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator & MutantStack<T>::iterator::operator -- (int tmp)
{
	MutantStack<T>::iterator ret = *this;
	tmp--;
	this->mItr--;
	return ret;
}

template <typename T>
T MutantStack<T>::iterator::operator * (void) const
{
	return *(this->mItr);
}

template <typename T>
bool MutantStack<T>::iterator::operator == (MutantStack<T>::iterator const & other) const
{
	return this->mItr == other.mItr;
}

template <typename T>
bool MutantStack<T>::iterator::operator != (MutantStack<T>::iterator const & other) const
{
	return this->mItr != other.mItr;
}

template <typename T>
bool operator == (MutantStack<T> const & s1, MutantStack<T> const & s2)
{
	return s1.mStack == s2.mStack;
}

template <typename T>
bool operator != (MutantStack<T> const & s1, MutantStack<T> const & s2)
{
	return s1.mStack != s2.mStack;
}

template <typename T>
bool operator < (MutantStack<T> const & s1, MutantStack<T> const & s2)
{
	return s1.mStack < s2.mStack;
}

template <typename T>
bool operator <= (MutantStack<T> const & s1, MutantStack<T> const & s2)
{
	return s1.mStack <= s2.mStack;
}

template <typename T>
bool operator > (MutantStack<T> const & s1, MutantStack<T> const & s2)
{
	return s1.mStack > s2.mStack;
}

template <typename T>
bool operator >= (MutantStack<T> const & s1, MutantStack<T> const & s2)
{
	return s1.mStack >= s2.mStack;
}

#endif