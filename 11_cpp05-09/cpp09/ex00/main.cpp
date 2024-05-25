#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(void)
{
    try
    {
        BitcoinExchange exchanger;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }

    std::map<std::string, double> data;
    
    
    return 0;
}