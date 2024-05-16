#include "Span.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>

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
	Span e1 = Span(4);
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