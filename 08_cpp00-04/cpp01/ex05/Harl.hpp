#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <string>

class Harl
{
private:
	std::string mLevel[4];
	void (Harl::*mCompl[4])(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl();
	void complain(std::string level);
};

#endif