#pragma once
#ifndef __BITCOINT_EXCHANGE_H__
#define __BITCOINT_EXCHANGE_H__

#include <map>
#include <string>
#include <stdexcept>

class Exchanger
{
public:
    Exchanger() throw(std::invalid_argument);
    ~Exchanger();
    Exchanger(Exchanger const & org);
    Exchanger & operator = (Exchanger const & org);
    static bool isValidDate(std::string const & date) throw();
    static bool isValieValue(int const & value) throw();
private:
    std::map<std::string, double> mDB;
};

#endif