#include "RPN.hpp"
#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>

RPN::RPN()
{}

RPN::RPN(RPN const & org)
{
    *this = org;
}

RPN::~RPN()
{}

RPN & RPN::operator = (RPN const & org)
{
    if (this != &org)
    {
        this->mMemory = org.mMemory;
    }
    return *this;
}

void RPN::calculate(std::string const & exp)
{
    std::size_t index = 0;
    bool isNum = true; /* false is space */
    if (exp.length() <= 1)
    {
        throw std::logic_error("invalid expression.");
    }
    while (index < exp.length())
    {
        while (index < exp.length() && !isOperator(exp[index], isNum))
        {
            this->pushNum(exp[index], isNum);
            index++;
        }
        if (index == exp.length() || this->mMemory.size() < 2)
        {
            throw std::logic_error("invalid expression.");
        }
        int n2 = this->mMemory.top();
        this->mMemory.pop();
        int n1 = this->mMemory.top();
        this->mMemory.pop();
        switch(exp[index])
        {
            case '+' :
                this->mMemory.push(n1 + n2);
                break;
            case '-' :
                this->mMemory.push(n1 - n2);
                break;
            case '*' :
                this->mMemory.push(n1 * n2);
                break;
            case '/' :
                if (n2 == 0)
                {
                    throw std::logic_error("dividing 0 is not allowed.");
                }
                this->mMemory.push(n1 / n2);
                break;
        }
        isNum = false;
        index++;
    }

    int ret = this->mMemory.top();
    this->mMemory.pop();
    if (!this->mMemory.empty())
    {
        throw std::logic_error("invalid expression : left number.");
    }
    std::cout << ret << std::endl;
}

void RPN::pushNum(int const & ch, bool & isNum)
{
    if (isNum && std::isdigit(ch))
    {
        this->mMemory.push(ch - '0');
        isNum = false;
    }
    else if (!isNum && ch == ' ')
    {
        isNum = true;
    }
    else if ((!isNum && std::isdigit(ch)) || (isNum && ch == ' '))
    {
        throw std::logic_error("invalid expression : usage [num/op][space] ... [num/op]");
    }
}

bool RPN::isOperator(int const & ch, bool & isNum)
{
    if (std::isdigit(ch) || ch == ' ')
    {
        return false;
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        if (isNum)
        {
            return true;
        }
        else
        {
            throw std::logic_error("invalid expression : usage [num/op][space] ... [num/op]");
        }
    }
    throw std::logic_error("unrecognized element.");
    return false;
}