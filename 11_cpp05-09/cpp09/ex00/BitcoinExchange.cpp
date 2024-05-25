#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
    this->mDB.clear();
    fillData(this->mDB, "data.csv");
    std::map<struct date, double>::const_iterator it;
    for (it = this->mDB.begin(); it != this->mDB.end(); it++)
    {
        bool isValidDate = (it->first.year == -1 || it->first.month == -1 || it->first.day == -1);
        if (!isValidDate || it->second == -1)
        {
            throw std::logic_error("invalid DB file");
        }
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & org)
{
    *this = org;
}

BitcoinExchange::~BitcoinExchange()
{
    this->mDB.clear();
}

BitcoinExchange & BitcoinExchange::operator = (BitcoinExchange const & org)
{
    if (this != &org)
    {
        this->mDB.clear();
        this->mDB = org.mDB;
    }
    return *this;
}

void BitcoinExchange::fillData(std::map<struct date, double> & data, char const * const fileName)
{
    std::string line;
    std::ifstream file;
    file = openFile(fileName, line);
    BitcoinExchange::addData(data, line);
    while (std::getline(file, line))
    {
        BitcoinExchange::addData(data, line);
    }
    file.close();
}

void BitcoinExchange::exchange(std::map<struct date, double> const & data) const
{
    std::map<struct date, double>::const_iterator dataIt;
    for (dataIt = data.begin(); dataIt != data.end(); dataIt++)
    {
        try
        {
            BitcoinExchange::validDate(dataIt->first);
            std::map<struct data, double>::const_iterator toFind = this->findData(dataIt->first);
            if (dataIt->second == -1)
            {
                throw std::logic_error("invalid value");
            }
            std::cout.precision(2);
            std::cout << dataIt->first.year << '-' << dataIt->first.month << '-' << dataIt->first.day;
            std::cout << " => " << dataIt->second << " = " << dataIt->second * toFind->second << std::endl;
        }
        catch(std::exception const & e)
        {
            std::cout << "Error : " << e.what() << std::endl;
        }
    }
}