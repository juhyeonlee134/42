#pragma once
#ifndef __P_MERGE_ME_H__
#define __P_MERGE_ME_H__

#include <iostream>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(PmergeMe const & org);
    ~PmergeMe();
    PmergeMe & operator = (PmergeMe const & org);
    void sort(unsigned int * const arr, std::size_t const size);
};

#endif