#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <iostream>
#include <exception>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe mergeMe;
        std::size_t const size = argc - 1;
        mergeMe.fill(argv + 1, size);
        mergeMe.printBefore();
        if (mergeMe.isSorted())
        {
            mergeMe.printAfter();
        }
        else
        {
            mergeMe.sort();
            mergeMe.printAfter();
        }
    }
    catch(std::exception const & e)
    {
        std::cout << "Error" << std::endl;
    }
    return 0;
}