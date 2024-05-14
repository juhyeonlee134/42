#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <exception>
#include <iostream>

int main(void)
{
	try
	{
		std::vector<int>vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		std::vector<int>::iterator vecIt = easyfind< std::vector<int> >(vec, 2);
		std::cout << *vecIt << '\n';

		std::deque<int>deq;
		deq.push_back(9);
		deq.push_back(8);
		deq.push_back(7);
		std::deque<int>::iterator deqIt = easyfind< std::deque<int> >(deq, 9);
		std::cout << *deqIt << '\n';

		std::list<int>lst;
		lst.push_back(-1);
		lst.push_back(0);
		lst.push_back(1);
		std::list<int>::iterator lstIt = easyfind< std::list<int> >(lst, 0);
		std::cout << *lstIt << '\n';

		std::vector<double>vecD;
		vecD.push_back(1.1);
		vecD.push_back(2.2);
		std::vector<double>::iterator vecDIt = easyfind< std::vector<double> >(vecD, 2.2);
		std::cout << *vecDIt << '\n';
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}