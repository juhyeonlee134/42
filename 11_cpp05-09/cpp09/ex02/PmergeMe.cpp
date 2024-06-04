#include "PmergeMe.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

PmergeMe::PmergeMe()
{
	throw std::exception();
}

PmergeMe::PmergeMe(char const * const strs[], long const & size)
{
	if (size <= 0 || strs == NULL || strs[0] == NULL)
	{
		throw std::exception();
	}
	this->mArr = new unsigned int[size];
	this->mSize = static_cast<std::size_t>(size);
	this->mTime = 0;
	for (std::size_t index = 0; index < this->mSize; index++)
	{
		long num = std::atol(strs[index]);
		std::stringstream stream;
		std::string str;
		stream << num;
		stream >> str;
		if (num < 0 || str.compare(strs[index]) != 0)
		{
			throw std::exception();
		}
		this->mArr[index] = static_cast<unsigned int>(num);
	}
}

PmergeMe::PmergeMe(PmergeMe const & org)
{
	if (org.mSize == 0 || org.mArr == NULL)
	{
		throw std::exception();
	}
	this->mArr = new unsigned int[org.mSize];
	this->mSize = org.mSize;
	this->mTime = org.mTime;
	std::copy(org.mArr, org.mArr + org.mSize, this->mArr);
}

PmergeMe::~PmergeMe()
{
	if (this->mArr != NULL)
	{
		delete[] this->mArr;
	}
}

PmergeMe & PmergeMe::operator = (PmergeMe const & org)
{
	if (this != &org)
	{
		if (org.mSize == 0 || org.mArr == NULL)
		{
			throw std::exception();
		}
		if (this->mArr != NULL)
		{
			delete[] this->mArr;
		}
		this->mArr = new unsigned int(org.mSize);
		this->mSize = org.mSize;
		this->mTime = org.mTime;
		std::copy(org.mArr, org.mArr + org.mSize, this->mArr);
	}
	return *this;
}

bool PmergeMe::isSorted(void) const
{
	if (this->mSize == 1)
	{
		return true;
	}
	for (std::size_t index = 1; index < this->mSize; index++)
	{
		if (this->mArr[index - 1] > this->mArr[index])
		{
			return false;
		}
	}
	return true;
}

void PmergeMe::printArr(void) const
{
	for (std::size_t index = 0; index < this->mSize; index++)
	{
		std::cout << this->mArr[index] << ' ';
	}
	std::cout << std::endl;
}

void PmergeMe::printTime(char const * const type) const
{
	std::cout << "Time to process a range of ";
	std::cout << std::setw(3) << std::right << this->mSize;
	std::cout << " elements with " << type << " : ";
	std::cout << std::fixed << std::setprecision(6) << this->mTime;
	std::cout << " us" << std::endl;
}

unsigned long PmergeMe::getJacopsthal(std::size_t const& index)
{
	static std::vector<unsigned long> buffer;

	if (index < buffer.size())
	{
		return buffer[index];
	}
	else if (index == 1)
	{
		buffer.push_back(0);
		buffer.push_back(1);
		return 1;
	}
	unsigned long n = getJacopsthal(index - 1);
	unsigned long m = getJacopsthal(index - 2);
	unsigned long ret = n + 2 * m;
	buffer.push_back(ret);
	return ret;
}