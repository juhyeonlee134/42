#pragma once
#ifndef __MUTANT_STACK_H__
#define __MUTANT_STACK_H__

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
	T top(void) const;
	bool empty(void) const;
	unsigned int size(void) const;
	void push(T const e);
	void pop(void);

	class iterator
	{
	public:
		iterator();
		iterator(typename std::deque<T>::iterator const itr);
		iterator(iterator const & org);
		~iterator();
		iterator & operator = (iterator const & org);
		iterator & operator ++ (void);
		iterator & operator ++ (int tmp);
		iterator & operator -- (void);
		iterator & operator -- (int tmp);
		T operator * (void) const;
		bool operator == (iterator const & other) const;
		bool operator != (iterator const & other) const;
	private:
		typename std::deque<T>::iterator mItr;
	};
	MutantStack<T>::iterator begin(void) const;
	MutantStack<T>::iterator end(void) const;
private:
	std::stack<T, std::deque<T> > mStack;
};

template <typename T>
bool operator == (MutantStack<T> const & s1, MutantStack<T> const & s2);
template <typename T>
bool operator != (MutantStack<T> const & s1, MutantStack<T> const & s2);
template <typename T>
bool operator < (MutantStack<T> const & s1, MutantStack<T> const & s2);
template <typename T>
bool operator <= (MutantStack<T> const & s1, MutantStack<T> const & s2);
template <typename T>
bool operator > (MutantStack<T> const & s1, MutantStack<T> const & s2);
template <typename T>
bool operator >= (MutantStack<T> const & s1, MutantStack<T> const & s2);

#include "MutantStack.tpp"

#endif