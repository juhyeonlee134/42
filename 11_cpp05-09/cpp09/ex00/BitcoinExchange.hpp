#pragma once
#ifndef __BITCOIN_EXCHANGE_H__
#define __BITCOIN_EXCHANGE_H__

#include <map>
#include <string>
#include <fstream>

struct date
{
    int year;
    int month;
    int day;
};

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & org);
    ~BitcoinExchange();
    BitcoinExchange & operator = (BitcoinExchange const & org);
    void exchange(std::map<struct date, double> const & data) const;
    void fillData(std::map<struct date, double> & data, char const * const fileName);
private:
    std::map<struct date, double> mDB;

    static std::ifstream openFile(char const * const fileName, std::string & line);

    static void validDate(struct date const & date);
    std::map<struct data, double>::const_iterator & findData(struct date const & date) const;

    static void addData(std::map<struct date, double> & data, std::string const & str) throw();
    static struct date & convertDate(std::string const & str);
    static double & convertDouble(std::string const & str);

    static bool compareYear(struct date const & d1, struct date const & d2);
};

#endif