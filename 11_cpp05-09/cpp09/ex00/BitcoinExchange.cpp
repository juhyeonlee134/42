#include "BitcoinExchange.hpp"
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
    this->mDB.clear();

    std::ifstream file;
    file.open("data.csv");
    if (!file.is_open())
    {
        throw std::logic_error("not found DB file");
    }

    std::string line;
    if (!std::getline(file, line))
    {
        throw std::logic_error("no data in DB file");
    }
    try
    {
        isValidFromat(line, ",");
        while (std::getline(file, line))
        {
            addData(this->mDB, line);
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        file.close();
    }
    file.close();
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
        this->mDB = org.mDB;
    }
    return *this;
}

void BitcoinExchange::isValidFromat(std::string const & str, std::string const & del)
{
    std::string diff = "date" + del + "exchange_rate";
    if (str.compare(diff) != 0)
    {
        throw std::logic_error("invalid format specification : \"date,exchange_rate\"");
    }
}

void BitcoinExchange::addData(std::map<std::string, double> & db, std::string const & str)
{
    std::size_t spLoc = str.find(',');
    if (spLoc == std::string::npos)
    {
        throw std::logic_error("invalid format : only \"day,value\"");
    }
    
    std::string date = str.substr(0, spLoc);
    isValidDate(date);
    
    std::string vStr = str.substr(spLoc + 1, str.length() - spLoc - 1);
    double value = std::atof(vStr.c_str());
    if (!isNum(vStr))
    {
        throw std::logic_error("invalid format : number only");
    }

    std::map<std::string, double>::iterator it = db.find(date);
    if (it == db.end())
    {
        db[date] = value;
    }
}

void BitcoinExchange::isValidDate(std::string const & date)
{
    std::size_t firstHyphen = date.find('-');
    if (firstHyphen == std::string::npos)
    {
        throw std::logic_error("invalid date : YYYY-MM-DD");
    }

    std::size_t secondHyphen = date.rfind('-');
    if (secondHyphen == std::string::npos)
    {
        throw std::logic_error("invalid date : YYYY-MM-DD");
    }

    std::string year = date.substr(0, firstHyphen);
    std::string month = date.substr(firstHyphen + 1, secondHyphen - firstHyphen - 1);
    std::string day = date.substr(secondHyphen + 1, date.length() - secondHyphen - 1);
    if (!isAllNum(year) || !isAllNum(month) || !isAllNum(day))
    {
        throw std::logic_error("invalid date : contain only number");
    }

    int nYear = std::atoi(year.c_str());
    if (nYear < 2009)
    {
        throw std::logic_error("invalid year : only after 2009");
    }

    int nMonth = std::atoi(month.c_str());
    if (nMonth < 1 || nMonth > 12)
    {
        throw std::logic_error("invalid month : only between 1 ~ 12");
    }

    bool isLeap = false;
    if (nYear % 4 == 0)
    {
        isLeap = true;
        if (nYear % 100 == 0)
        {
            isLeap = false;
            if (nYear % 400 == 0)
            {
                isLeap = true;
            }
        }
    }

    bool is30Day = (nMonth == 4 || nMonth == 6 || nMonth == 9 || nMonth == 11);
    bool is31Day = (nMonth == 1 || nMonth == 3 || nMonth == 5 || nMonth == 7 || nMonth == 8 || nMonth == 10 || nMonth == 12);

    int nDay = std::atoi(day.c_str());
    if (is30Day)
    {
        if (nDay < 1 || nDay > 30)
        {
            throw std::logic_error("invalid day : in 1, 3, 5, 7, 9, 10, 12, only able between 1 ~ 30");
        }
    }
    else if (is31Day)
    {
        if (nDay < 1 || nDay > 31)
        {
            throw std::logic_error("invalid day : in 4, 6, 9, 11, only albe between 1 ~ 31");
        }
    }
    else if (isLeap)
    {
        if (nDay < 1 || nDay > 29)
        {
            throw std::logic_error("invalid day : in February leap year, only able between 1 ~ 29");
        }
    }
    else
    {
        if (nDay < 1 || nDay > 28)
        {
            throw std::logic_error("invalid day : in February, only able between 1 ~ 28");
        }
    }
}

bool BitcoinExchange::isAllNum(std::string const & str)
{
    for (std::size_t index = 0; index < str.length(); index++)
    {
        if (!isnumber(str[index]))
        {
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::isNum(std::string const & str)
{
    std::size_t index;
    for (index = 0; index < str.length() && isnumber(str[index]); index++);
    if (str[index] == '.')
    {
        for (std::size_t cnt = index + 1; cnt < str.length(); cnt++)
        {
            if (!isnumber(str[cnt]))
            {
                return false;
            }
        }
    }
    return true;
}
