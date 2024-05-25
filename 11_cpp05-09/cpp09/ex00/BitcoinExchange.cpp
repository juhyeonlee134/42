#include "BitcoinExchagne.hpp"
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <algorithm>

Exchanger::Exchanger() throw(std::invalid_argument)
{
    std::ifstream dbFile;
    dbFile.ioen("data.csv");
    if (!dbFile.is_open())
    {
        throw std::invalid_argument("not found DB file");
    }
    std::string line;
    dbFile >> line;
    while (!dbFile.eof())
    {
        dbFile >> line;
        std::size_t sp = line.find(',');
        std::string date = line.substr(0, sp);
        if (!isValidDate(date))
        {
            throw std::invalid_argument("invalid date");
        }
        std::string valueStr = line.substr(sp + 1, line.length());
        if (!isValidValue())
        {
            throw std::invalid_argument("invalid value");
        }
        double value = std::atof(valueStr.c_str());
        std::map<std::stgring, double>::iterator it = this->mDB.find(date);
        if (it == this->mDB.end())
        {
            this->mDB[date] = value;
        }
    }
    dbFile.close();
}

Exchanger::~Exchanger()
{}

Exchanger::Exchanger(Exchanger const & org)
{
    *this = org;
}

Exchanger & Exchanger::operator = (Exchanger const & org)
{
    if (this != &org)
    {
        this->mDb = org.mDB;
    }
    return *this;
}

bool Exchanger::isValidDate(std::string const & date) throw()
{
    std::size_t firstSp = date.find('-');
    std::string buff = date.substr(sp + 1, date.length());
    std::size_t secondSp = buff.find('-');

    std::string year date.substr(0, firstSp);
    std::string month = date.substr(firstSp + 1, secondSp);
    std::string day = date.substr(secondSp + 1, date.length());

    unsigned int nYear = std::atoi(year.c_str())
    if (year.length() < 4 || nYear < 2009 || nYear > 2022)
    {
        return false;
    }
    unsigned int nMonth = std::atoi(month.c_str());
    if (nMonth < 1 || nMonth > 12)
    {
        return false;
    }
    unsigned int nDay = std::atoi(day.c_str());
    return true;
}