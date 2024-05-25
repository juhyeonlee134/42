#pragma once
#ifndef __BITCOINT_EXCHANGE_H__
#define __BITCOINT_EXCHANGE_H__

#include <map>
#include <string>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & org);
    ~BitcoinExchange();
    BitcoinExchange & operator = (BitcoinExchange const & org);
    static void addData(std::map<std::string, double> & db, std::string const & str);
private:
    std::map<std::string, double> mDB;
    static void isValidFromat(std::string const & str, std::string const & del);
    static void isValidDate(std::string const & date);
    static bool isAllNum(std::string const & str);
    static bool isNum(std::string const & str);
};

#endif