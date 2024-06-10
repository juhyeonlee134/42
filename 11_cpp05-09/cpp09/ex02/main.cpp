#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Error: no elements to sort" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe org(argv + 1, argc - 1);
        PmergeMe vec(org);
        PmergeMe deq(org);

        std::cout << "Before: ";
        org.printArr();

        vec.sort<std::vector<int> >();
        deq.sort<std::deque<int> >();
        vec.isSorted();
        deq.isSorted();
        vec.checkSame(deq);
        deq.checkSame(vec);
        
        org = vec;
        std::cout << "After: ";
        org.printArr();

        vec.printTime("std::vector");
        deq.printTime("std::deque");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
