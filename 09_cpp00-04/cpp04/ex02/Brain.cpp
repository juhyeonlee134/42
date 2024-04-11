#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain creat" << std::endl;
}

Brain::Brain(Brain const& org)
{
    std::cout << "Brain copy" << std::endl;
    *this = org;
}

Brain::~Brain()
{
    std::cout << "Brain remove" << std::endl;
}

Brain& Brain::operator = (Brain const& org)
{
    if (this == &org)
    {
        return *this;
    }
    for (size_t index = 0; index < 100; index++)
    {
        this->ideas[index] = org.getIdea(index);
    }
    return *this;
}

std::string Brain::getIdea(size_t const index) const
{
    return this->ideas[index];
}

void Brain::setIdea(std::string const& idea, size_t const index)
{
    this->ideas[index] = idea;
}