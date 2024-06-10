#include "PmergeMe.hpp"
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(char const * const strs[], int const size)
{
	if (size == 0)
	{
		throw std::logic_error("Error: no elements to ");
	}
	this->mArr = new int[size];
	this->mSize = size;
	this->mTime = 0;
	for (int index = 0; index < size; index++)
	{
		long num = std::atol(strs[index]);
		std::stringstream ss;
		std::string toCheck;
		ss << num;
		ss >> toCheck;
		if (toCheck != strs[index] || num < 0)
		{
			throw std::logic_error("Error: invalid input");
		}
		this->mArr[index] = num;
	}
}

PmergeMe::PmergeMe(PmergeMe const& org)
{
	this->mArr = new int[org.mSize];
	this->mSize = org.mSize;
	this->mTime = org.mTime;
	for (int index = 0; index < this->mSize; index++)
	{
		this->mArr[index] = org.mArr[index];
	}
}

PmergeMe::~PmergeMe()
{
	delete[] this->mArr;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& org)
{
	delete[] this->mArr;
	this->mArr = new int[org.mSize];
	this->mSize = org.mSize;
	this->mTime = org.mTime;
	for (int index = 0; index < this->mSize; index++)
	{
		this->mArr[index] = org.mArr[index];
	}
	return *this;
}

void PmergeMe::printArr(void) const
{
	for (int index = 0; index < this->mSize; index++)
	{
		std::cout << this->mArr[index] << ' ';
	}
	std::cout << std::endl;
}

void PmergeMe::isSorted(void) const
{
	for (int index = 1; index < this->mSize; index++)
	{
		if (this->mArr[index - 1] > this->mArr[index])
		{
			throw std::logic_error("Error: not sorted");
		}
	}
}

void PmergeMe::checkSame(PmergeMe const& other)
{
	if (this->mSize != other.mSize)
	{
		throw std::logic_error("Error: different sizes");
	}
	for (int index = 0; index < this->mSize; index++)
	{
		if (this->mArr[index] != other.mArr[index])
		{
			throw std::logic_error("Error: different elements");
		}
	}
}

void PmergeMe::printTime(char const* const type) const
{
	std::cout << "Time to process a range of " << std::setw(3) << this->mSize;
	std::cout << " elementss with " << type << " : ";
	std::cout << std::fixed << std::setprecision(6) << this->mTime << " us" << std::endl;
}

idx_t PmergeMe::jacobsthal(int const n)
{
	static int buffer[20] = { 0,1 };
	static int size = 2;
	if (n >= size)
	{
		buffer[n] = jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
		size++;
	}
	return buffer[n];
}
