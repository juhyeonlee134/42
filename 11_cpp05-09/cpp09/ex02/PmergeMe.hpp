#pragma once
#ifndef __P_MERGE_ME_H__
#define __P_MERGE_ME_H__

#include <deque>
#include <vector>
#include <iostream>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(PmergeMe const & org);
    ~PmergeMe();
    PmergeMe & operator = (PmergeMe const & org);
    void fill(char const * const strs[], std::size_t const size);
    void printBefore(void) const;
    void printAfter(void) const;
    void sort(void);
    bool isSorted(void) const;
private:
    bool isSame(void) const;

    double mDeqTime;
    double mVecTime;
    std::deque<unsigned int> mDeq;
    std::vector<unsigned int> mVec;
};

#endif