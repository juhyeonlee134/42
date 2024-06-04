#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <deque>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <exception>

PmergeMe::PmergeMe(void)
{
    throw std::exception();
}

PmergeMe::PmergeMe(char **strs, std::size_t const& size)
{
	if (size == 0)
	{
		throw std::exception();
	}
	this->mArr = new unsigned int[size];
	this->mSize = size;

	for (std::size_t index = 0; index < size; index++)
	{
		long num = std::atol(strs[index]);
		std::stringstream stream;
		std::string toCheck;
		stream << num;
		stream >> toCheck;
		if (toCheck.compare(strs[index]) != 0 || num < 0)
		{
			throw std::exception();
		}
		this->mArr[index] = static_cast<unsigned int>(num);
	}

	std::cout << "Before: ";
	for (std::size_t index = 0; index < this->mSize; index++)
	{
		std::cout << this->mArr[index] << ' ';
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const& org)
{
    if (org.mSize == 0)
    {
        throw std::exception();
    }
    this->mArr = new unsigned int[org.mSize];
    this->mSize = org.mSize;
    for (std::size_t index = 0; index < this->mSize; index++)
    {
        this->mArr[index] = org.mArr[index];
    }
}

PmergeMe::~PmergeMe(void)
{
	if (this->mArr)
	{
		delete[] this->mArr;
	}
}

PmergeMe& PmergeMe::operator = (PmergeMe const& org)
{
	if (this != &org)
	{
		if (this->mArr)
		{
			delete[] this->mArr;
		}
		if (org.mSize == 0)
		{
            throw std::exception();
		}
		this->mArr = new unsigned int[org.mSize];
		this->mSize = org.mSize;
		for (std::size_t index = 0; index < this->mSize; index++)
		{
			this->mArr[index] = org.mArr[index];
		}
	}
	return *this;
}

void PmergeMe::sort(void)
{
	clock_t start, end;
	double vTime, dTime;

	std::vector<unsigned int> vec, vRet;
	std::deque<unsigned int> deq, dRet;
	std::vector<std::pair<unsigned int, unsigned int> > vPairs;
	std::deque<std::pair<unsigned int, unsigned int> > dPairs;
	for (std::size_t index = 0; index < this->mSize; index++)
	{
		vec.push_back(this->mArr[index]);
		deq.push_back(this->mArr[index]);
	}

	start = clock();
	setPairs(vec, vPairs);
	merge<std::vector<std::pair<unsigned int, unsigned int> > >(vPairs.begin(), vPairs.end());
	vRet.push_back(vPairs[0].second);
	vRet.push_back(vPairs[0].first);
	insert(vRet, vPairs.begin(), vPairs.end(), 1);
	for (std::size_t index = 0; index < vec.size(); index++)
	{
		vec[index] = vRet[index];
	}
	end = clock();
	vTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = clock();
	setPairs(deq, dPairs);
	merge<std::deque<std::pair<unsigned int, unsigned int> > >(dPairs.begin(), dPairs.end());
	insert(dRet, dPairs.begin(), dPairs.end(), 1);
	for (std::size_t index = 0; index < deq.size(); index++)
	{
		deq[index] = dRet[index];
	}
	end = clock();
	dTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	for (std::size_t index = 0; index < this->mSize; index++)
	{
		if (vRet[index] != dRet[index])
		{
			std::cout << "Fail to sort" << std::endl;
			return;
		}
		this->mArr[index] = vRet[index];
	}
	std::cout << "After:  ";
	for (std::size_t index = 0; index < this->mSize; index++)
	{
		std::cout << this->mArr[index] << ' ';
	}
	std::cout << std::endl;
    std::cout << "Time to process a range of " << std::setw(3) << std::right << this->mSize;
	std::cout << " element with std::vector : " << std::fixed << std::setprecision(6) << vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(3) << std::right << this->mSize;
    std::cout << " element with std::deque : " << std::fixed << std::setprecision(6) << dTime << " us" << std::endl;
}

void PmergeMe::printArr(void) const
{
    std::cout << "After:  ";
    for (std::size_t index = 0; index < this->mSize; index++)
    {
        std::cout << this->mArr[index] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << std::setw(3) << std::right << this->mSize;
    std::cout << " elements with std::vector : 0.000000 us" << std::endl;
    std::cout << "Time to process a range of " << std::setw(3) << std::right << this->mSize;
    std::cout << " elements with std::deque : 0.000000 us" << std::endl;
}

bool PmergeMe::isSorted(void) const
{
    for (std::size_t index = 1; index < this->mSize; index++)
    {
        if (this->mArr[index - 1] > this->mArr[index])
        {
            return false;
        }
    }
    return true;
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
	unsigned long n = this->getJacopsthal(index - 1);
	unsigned long m = this->getJacopsthal(index - 2);
	unsigned long ret = n + 2 * m;
	buffer.push_back(ret);
	return ret;
}
