#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main(void)
{
    std::vector<int>vec = {1, 2, 3, 4};
    easyfind(vec, 5);
    std::deque<int>deq = {9, 8, 7, 6};
    easyfind(deq, 9);
    std::list<int>lst = {-1, 0, 1};
    easyfind(lst, 0);
    return 0;
}