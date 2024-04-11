#pragma once
#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <string>

class Brain
{
public:
    Brain();
    Brain(Brain const& org);
    ~Brain();
    Brain& operator = (Brain const& org);
    std::string getIdea(size_t const index) const;
    void setIdea(std::string const& idea, size_t const index);
private:
    std::string ideas[100];
};

#endif