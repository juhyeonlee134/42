#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cout << "Error : usage RPN \"[exp]\"" << std::endl;
        return 1;
    }
    RPN calcurator;
    std::string exp = argv[1];
    try
    {
        calcurator.calculate(exp);
    }
    catch(std::exception const & e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }
    return 0;
}