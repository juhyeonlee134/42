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
    while (index < exp.length())
    {
        while (index < exp.length() && !isOperator(exp[index]))
        {
            this->pushNum(exp[index], isNum);
            index++;
        }

        if (this->mMemory.empty() || this->mMemory.size() < 2)
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
        throw std::logic_error("invalid expression : left one number.");
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

bool RPN::isOperator(int const & ch)
{
    if (std::isdigit(ch))
    {
        return false;
    }
    else if (ch == ' ')
    {
        return false;
    }
    else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return true;
    }
    throw std::logic_error("unrecognized element.");
    return false;
}