#pragma once
#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	MutantStack();
	MutantStack(MutantStack const & org);
	~MutantStack();
	MutantStack & operator = (MutantStack const & org);
	class iterator : public std::deque<T>::iterator
	{
	public:
		iterator();
		iterator(typename std::deque<T>::iterator const & it);
		iterator(iterator const & org);
		iterator & operator = (iterator const & org);
		~iterator();
	private:
		typename std::deque<T>::iterator it;
	};
	MutantStack<T>::iterator begin(void);
	MutantStack<T>::iterator end(void);
};

#include "MutantStack.tpp"

#endif