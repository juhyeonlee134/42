#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <iostream>

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "\ntest" << std::endl;
	MutantStack<int>::const_iterator i = mstack.begin();
	MutantStack<int>::iterator j = mstack.begin();
	std::cout << *i << ' ' << *j << std::endl;
	// *i = 100;
	*j = 100;
	std::cout << *i << ' ' << *j << std::endl;

	MutantStack<int>::const_reverse_iterator rIt;
	for (rIt = mstack.rbegin(); rIt != mstack.rend(); rIt++)
	{
		std::cout << *rIt << ' ';
	}
	std::cout << std::endl;

	MutantStack<double> mstackD;
	mstackD.push(1.1);
	mstackD.push(2.2);
	mstackD.push(3.3);
	mstackD.push(4.4);
	mstackD.push(5.5);
	mstackD.push(6.6);
	mstackD.push(7.7);
	mstackD.push(8.8);
	MutantStack<double>::iterator dIt;
	for (dIt = mstackD.begin(); dIt != mstackD.end(); dIt++)
	{
		std::cout << *dIt << ' ';
	}
	std::cout << std::endl;
	dIt = mstackD.begin();
	while (dIt != mstackD.end())
	{
		mstackD.pop();
	}
	std::cout << mstackD.size() << std::endl;

	MutantStack<std::string> strs;
	strs.push("AAA");
	strs.push("BBB");
	strs.push("CCC");
	MutantStack<std::string> copy;
	copy = strs;
	copy.pop();
	MutantStack<std::string>::iterator sIt;
	for (sIt = strs.begin(); sIt != strs.end(); sIt++)
	{
		std::cout << *sIt << std::endl;
	}
	for (sIt = copy.begin(); sIt != copy.end(); sIt++)
	{
		std::cout << *sIt << std::endl;
	}

	std::cout << "\ncopy to list" << std::endl;
	std::list<std::string> strList;
	while(!strs.empty())
	{
		strList.push_back(strs.top());
		strs.pop();
	}
	std::list<std::string>::iterator lIt;
	for (lIt = strList.begin(); lIt != strList.end(); lIt++)
	{
		std::cout << *lIt << std::endl;
	}
	std::cout << strs.size() << std::endl;
	return 0;
}