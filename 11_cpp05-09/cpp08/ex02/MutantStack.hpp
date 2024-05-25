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
	typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	MutantStack();
	MutantStack(MutantStack const & org);
	~MutantStack();
	MutantStack & operator = (MutantStack const & org);
	MutantStack<T>::iterator begin(void);
	MutantStack<T>::iterator end(void);
	MutantStack<T>::reverse_iterator rbegin(void);
	MutantStack<T>::reverse_iterator rend(void);
	MutantStack<T>::const_iterator begin(void) const;
	MutantStack<T>::const_iterator end(void) const;
	MutantStack<T>::const_reverse_iterator rbegin(void) const;
	MutantStack<T>::const_reverse_iterator rend(void) const;
};

#include "MutantStack.tpp"

#endif