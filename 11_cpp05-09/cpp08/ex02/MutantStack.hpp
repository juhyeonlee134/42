#pragma once
#ifndef __MUTANTSTACK_H__
#define __MUTANTSTACK_H__

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
	typedef typename MutantStack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(MutantStack const & org);
	~MutantStack();
	MutantStack & operator = (MutantStack const & org);
	MutantStack<T>::iterator begin(void);
	MutantStack<T>::iterator end(void);
};

#include "MutantStack.tpp"

#endif