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
		easyfind< std::vector<int> >(vec, 2);
		std::cout << "find\n";
		std::deque<int>deq;
		deq.push_back(9);
		deq.push_back(8);
		deq.push_back(7);
		easyfind< std::deque<int> >(deq, 9);
		std::cout << "find\n";
		std::list<int>lst;
		lst.push_back(-1);
		lst.push_back(0);
		lst.push_back(1);
		easyfind< std::list<int> >(lst, 0);
		std::cout << "find\n";
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}