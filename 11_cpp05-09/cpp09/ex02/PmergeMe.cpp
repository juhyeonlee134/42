#include "PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <vector>
#include <utility>
#include <iomanip>
#include <iostream>
#include <strstream>

PmergeMe::PmergeMe()
    : mDeqTime(0)
    , mVecTime(0)
{}

PmergeMe::PmergeMe(PmergeMe const & org)
{
    *this = org;
}

PmergeMe::~PmergeMe()
{}

PmergeMe & PmergeMe::operator = (PmergeMe const & org)
{
    if (this != &org)
    {}
    return *this;
}

void PmergeMe::fill(char const * const strs[], std::size_t const size)
{
    for (std::size_t index = 0; index < size; index++)
    {
        std::string str = strs[index];
        std::strstream stream;
        std::string checker;

        long num = std::atol(str.c_str());
        stream << num;
        stream >> checker;
        if (str != checker || num < 0 || num > 4294967295u)
        {
            std::exception();
        }
        this->mDeq.push_back(static_cast<unsigned int>(num));
        this->mVec.push_back(static_cast<unsigned int>(num));
    }
}

void PmergeMe::printBefore(void) const
{
    if (!this->isSame())
    {
        throw std::exception();
    }
    std::cout << "Before: ";
    for (std::size_t index = 0; index < this->mVec.size(); index++)
    {
        std::cout << this->mVec[index] << ' ';
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter(void) const
{
    if (!this->isSame())
    {
        throw std::exception();
    }
    std::cout << "After:  ";
    for (std::size_t index = 0; index < this->mVec.size(); index++)
    {
        std::cout << this->mVec[index] << ' ';
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of ";
    std::cout << std::setw(3) << std::right << this->mDeq.size();
    std::cout << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(5) << this->mDeqTime << " us" << std::endl;

    std::cout << "Time to process a range of ";
    std::cout << std::setw(3) << std::right << this->mVec.size();
    std::cout << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(5) << this->mVecTime << " us" << std::endl;
}

void PmergeMe::sort(void)
{}

bool PmergeMe::isSorted(void) const
{
    std::vector<unsigned int>::const_iterator curr = this->mVec.begin();
    std::vector<unsigned int>::const_iterator prev = this->mVec.begin();
    curr++;
    while (curr != this->mVec.end())
    {
        if (*prev > *curr)
        {
            return false;
        }
        curr++;
        prev++;
    }
    return true;
}

bool PmergeMe::isSame(void) const
{
    if (this->mDeq.size() != this->mVec.size())
    {
        return false;
    }
    for (std::size_t index = 0; index < this->mVec.size(); index++)
    {
        if (this->mDeq[index] != this->mVec[index])
        {
            return false;
        }
    }
    return true;
}