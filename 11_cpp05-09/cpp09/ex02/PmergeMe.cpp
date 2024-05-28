#include "PmergeMe.hpp"
#include <deque>
#include <vector>

PmergeMe::PmergeMe()
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

void PmergeMe::sort(unsigned int * const arr, std::size_t const size);
{
    std::deque<unsigned int> deq;
    std::vector<unsigned int> vec;

    for (std::size_t index = 0; index < size; index++)
    {
        deq.push_back(arr[index]);
        vec.push_back(arr[index]);
    }
}