#include "BitcoinExchange.hpp"
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cout << "Error : could not open file." << std::endl;
        return 1;
    }

    std::ifstream dataFile;
    std::string line;
    dataFile.open(argv[1]);
    try
    {
        if (!dataFile.is_open())
        {
            throw std::logic_error("Error : could not open file.");
        }
        if (!std::getline(dataFile, line))
        {
            throw std::logic_error("Error : data file is empty.");
        }
        if (line.compare("date | value") != 0)
        {
            throw std::logic_error("Error : invalid data format.");
        }
        if (!std::getline(dataFile, line))
        {
            throw std::logic_error("Error : data file is empty.");
        }
    }
    catch(std::exception const & e)
    {
        std::cout << e.what() << std::endl;
        dataFile.close();
        return 1;
    }

    try
    {
        BitcoinExchange exchanger;
        do
        {
            try
            {
                exchanger.exchange(line);
            }
            catch (std::exception const & e)
            {
                std::cout << e.what() << std::endl;
            }
        } while (std::getline(dataFile, line));
        
    }
    catch(std::exception const & e)
    {
        std::cout << e.what() << std::endl;
    }

    dataFile.close();
    return 0;
}