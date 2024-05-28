#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <iostream>
#include <strstream>
#include <exception>

static std::deque<unsigned int> convert(char const * const strs[], std::size_t const size);
static std::vector<unsigned int> convert(char const * const strs[], std::size_t const size);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    PmergeMe merger;
    unsigned int * arr = NULL;
    std::size_t const size = argc - 1;
    try
    {
        arr = convert(argv + 1, size);
        std::cout << "Before: ";
        printArr(arr, size);
        merger.sort(arr, size);
        delete[] arr;
    }
    catch(std::exception const & e)
    {
        std::cout << "Error" << std::endl;
        if (arr != NULL)
        {
            delete[] arr;
        }
    }
    return 0;
}

std::vector<unsigned int> convert(char const * const strs[], std::size_t const size)
{
    std::vector<unsigned int> vec;
    for (std::size_t index = 0; index < size; index++)
    {
        std::string str = strs[index];
        std::strstream strStream;
        std::string toCheck;

        long num = std::atol(str.c_str());
        strStream << num;
        strStream >> toCheck;
        if (str.compare(toCheck))
        {
            throw std::exception();
        }
        if (num < 0 || num > 4294967295u)
        {
            throw std::exception();
        }
        ret[index] = static_cast<unsigned int>(num);
    }
    return ret;
}

void printArr(unsigned int const * const arr, std::size_t const size)
{
    for (std::size_t index = 0; index < size; index++)
    {
        std::cout << arr[index] << ' ';
    }
    std::cout << std::endl;
}