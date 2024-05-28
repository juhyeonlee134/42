#pragma once
#ifndef __RPN_H__
#define __RPN_H__

#include <string>
#include <stack>

class RPN
{
public:
    RPN();
    RPN(RPN const & org);
    ~RPN();
    RPN & operator = (RPN const & org);
    void calculate(std::string const & exp);
private:
    std::stack<int> mMemory;
    void pushNum(int const & ch, bool & isNum);
    static bool isOperator(int const & ch, bool & isNum);
};

#endif