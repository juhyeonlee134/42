#include "Span.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill(T & container, unsigned int size)
{
	std::srand(std::time(NULL));
	for (unsigned int i = 0; i < size; i++)
	{
		container.push_back(std::rand());
	}
}

int main(void)
{
	Span sp = Span(5);
	Span many = Span(100000);
	Span test = Span(10);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		//sp.addNumber(100);

		std::list<int> lst;
		lst.clear();
		fill(lst, 10000);
		many.fillRange<std::list<int> >(lst.begin(), lst.end());

		std::cout << many.shortestSpan() << std::endl;
		std::cout << many.longestSpan() << std::endl;

		std::deque<int> deq;
		deq.clear();
		deq.push_back(-7);
		deq.push_back(99);
		deq.push_back(5);
		deq.push_back(100);
		deq.push_back(11);
		deq.push_back(20);
		deq.push_back(5);
		deq.push_back(-1);
		deq.push_back(7);
		deq.push_back(-100);
		test.fillRange<std::deque<int> >(deq.begin(), deq.end());

		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;

		//std::deque<std::string> deq;
		//deq.push_back("AAA");
		//deq.push_back("AAA");
		//deq.push_back("AAA");
		//deq.push_back("AAA");
		//e1.fillRange<std::deque<std::string> >(deq.begin(), deq.end());

		std::set<double> s;
		s.insert(1.1);
		s.insert(2.2);
		s.insert(3.3);
		s.insert(4.4);
		many.fillRange<std::set<double> >(s.begin(), s.end());
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}