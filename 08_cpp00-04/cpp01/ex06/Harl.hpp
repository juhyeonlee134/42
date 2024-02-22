#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <string>

enum Ecompl
{
	E_DEBUG, E_INFO, E_WARNING, E_ERROR, E_INVALID
};

struct Compl
{
	Ecompl index;
	std::string level;
};

class Harl
{
private:
	Compl mCompls[4];
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	Ecompl findIndex(std::string level);
public:
	Harl();
	void complain(std::string level);
};

#endif