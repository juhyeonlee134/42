#pragma once
#ifndef __BITCOIN_EXCHANGE_H__
#define __BITCOIN_EXCHANGE_H__

#include <map>
#include <string>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & org);
    ~BitcoinExchange();
    BitcoinExchange & operator = (BitcoinExchange const & org);
    void exchange(std::string const & line) const;
    std::map<std::string, double>::const_iterator findData(std::string const & date) const;
private:
    std::map<std::string, double> mDB;
};

void addData(std::map<std::string, double> & db, std::string const & date, std::string const & value);
void checkDate(std::string const & str);
bool isAllNum(std::string const & str);
double convertValue(std::string const & str);

#endif