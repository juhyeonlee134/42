#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
    this->mDB.clear();

    std::fstream file;
    file.open("data.csv");
    if (!file.is_open())
    {
        throw std::logic_error("Error : could not open DB file.");
    }

    std::string line;
    if (!std::getline(file, line))
    {
        throw std::logic_error("Error : DB file is empty.");
    }
    if (line.compare("date,exchange_rate") != 0)
    {
        throw std::logic_error("Error : invalid DB data format.");
    }
    while (std::getline(file, line))
    {
        std::size_t comma = line.find(',');
        if (comma == std::string::npos)
        {
            throw std::logic_error("Error : invalid DB data format.");
        }
        std::string date = line.substr(0, comma);
        std::string value = line.substr(comma + 1, line.length() - comma - 1);
        addData(this->mDB, date, value);
    }

    if (this->mDB.empty())
    {
        throw std::logic_error("Error : DB file is empty.");
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
        this->mDB.clear();
        this->mDB = org.mDB;
    }
    return *this;
}

void BitcoinExchange::exchange(std::string const & line) const
{
    std::size_t bar = line.find('|');
    if (bar == std::string::npos || bar == 0)
    {
        throw std::logic_error("Error : invalid format.");
    }
    if (line[bar - 1] != ' ' || line[bar + 1] != ' ')
    {
        throw std::logic_error("Error : invalid format.");
    }

    std::string dateStr = line.substr(0, bar - 1);
    std::string valueStr = line.substr(bar + 2, line.length() - bar - 2);
    double value = convertValue(valueStr);
    checkDate(dateStr);
    if (value < 0)
    {
        throw std::logic_error("Error : not a positive number.");
    }
    else if (value > 1000)
    {
        throw std::logic_error("Error : too large a number.");
    }
    std::map<std::string, double>::const_iterator it = this->findData(dateStr);
    if (it != this->mDB.end())
    {
        std::cout.precision(10);
        std::cout << dateStr << " => " << valueStr << " = " << value * it->second << std::endl;
    }
}

std::map<std::string, double>::const_iterator BitcoinExchange::findData(std::string const & date) const
{
    if (date.compare(this->mDB.begin()->first) < 0)
    {
        throw std::logic_error("Error : It's too far in the past.");
    }
    std::map<std::string, double>::const_iterator it = this->mDB.find(date);
    if (it != this->mDB.end())
    {
        return it;
    }
    std::map<std::string, double>::const_iterator curr = this->mDB.begin();
    std::map<std::string, double>::const_iterator prev = this->mDB.begin();
    curr++;
    while (curr != this->mDB.end())
    {
        if (date.compare(curr->first.c_str()) < 0 && date.compare(prev->first.c_str()) > 0)
        {
            break;
        }
        curr++;
        prev++;
    }
    return prev;
}

void addData(std::map<std::string, double> & db, std::string const & date, std::string const & value)
{
    checkDate(date);
    double valueData = convertValue(value);
    std::map<std::string, double>::iterator it = db.find(date);
    if (it == db.end())
    {
        db[date] = valueData;
    }
}

bool isAllNum(std::string const & str)
{
    for (std::size_t index = 0; index < str.length(); index++)
    {
        if (!std::isdigit(str[index]))
        {
            return false;
        }
    }
    return true;
}

double convertValue(std::string const & str)
{
    if (str.size() == 0)
    {
        throw std::logic_error("Error : empty value.");
    }

    std::size_t index = 0;
    while (index < str.length() && std::isdigit(str[index]))
    {
        index++;
    }
    if (str[index] == '.')
    {
        index++;
        while (index < str.length() && std::isdigit(str[index]))
        {
            index++;
        }
    }
    if (index != str.length())
    {
        throw std::logic_error("Error : only integer and float values are allowed.");
    }

    double value = std::atof(str.c_str());
    return value;
}

void checkDate(std::string const & str)
{
    if (str.size() == 0)
    {
        throw std::logic_error("Error : empty date.");
    }
    if (str.size() < 10)
    {
        throw std::logic_error("Error : invalid date format.");
    }
    std::size_t firstHyphen = str.find('-');
    std::size_t secondHyphen = str.rfind('-');
    bool notFound = (firstHyphen == std::string::npos || secondHyphen == std::string::npos);
    if (notFound || firstHyphen == secondHyphen)
    {
        throw std::logic_error("Error : invalid date format.");
    }

    std::string year = str.substr(0, firstHyphen);
    std::string month = str.substr(firstHyphen + 1, secondHyphen - firstHyphen - 1);
    std::string day = str.substr(secondHyphen + 1, str.length() - secondHyphen - 1);
    if (!isAllNum(year) || !isAllNum(month) || !isAllNum(day))
    {
        throw std::logic_error("Error : date only conatin number.");
    }

    int nYear = std::atoi(year.c_str());
    int nMonth = std::atoi(month.c_str());
    int nDay = std::atoi(day.c_str());
    if (nYear < 2009)
    {
        throw std::logic_error("Error : it's too far in the past.");
    }
    else if (nYear > 2023)
    {
        throw std::logic_error("Error : are you from the future?");
    }
    if (nMonth < 1 || nMonth > 12)
    {
        throw std::logic_error("Error : invalid month.");
    }

    bool isLeap = false;
    if (nYear % 4 == 0)
    {
        if (nYear % 100 == 0)
        {
            if (nYear % 400 == 0)
            {
                isLeap = true;
            }
            else
            {
                isLeap = false;
            }
        }
        else
        {
            isLeap = true;
        }
    }

    bool is30 = (nMonth ==  4 || nMonth == 6 || nMonth == 9 || nMonth == 11);
    bool is31 = (nMonth == 1 || nMonth == 3 || nMonth == 5 || nMonth == 7 || nMonth == 8 || nMonth == 10 || nMonth == 12);
    if (isLeap && nMonth == 2 && (nDay < 1 || nDay > 29))
    {
        throw std::logic_error("Error : not a valid day in a leap month.");
    }
    else if (!isLeap && nMonth == 2 && (nDay < 1 || nDay > 28))
    {
        throw std::logic_error("Error : not a valid day in february.");
    }
    else if (is31 && (nDay < 1 || nDay > 31))
    {
        throw std::logic_error("Error : not a valid day.");
    }
    else if (is30 && (nDay < 1 || nDay > 30))
    {
        throw std::logic_error("Error : not a valid day.");
    }
}
