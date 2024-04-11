#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Ecompl Harl::findIndex(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->mCompls[i].level)
		{
			return static_cast<Ecompl>(i);
		}
	}
	return E_INVALID;
}

Harl::Harl()
{
	this->mCompls[0].index = E_DEBUG;
	this->mCompls[0].level = "DEBUG";
	this->mCompls[1].index = E_INFO;
	this->mCompls[1].level = "INFO";
	this->mCompls[2].index = E_WARNING;
	this->mCompls[2].level = "WARNING";
	this->mCompls[3].index = E_ERROR;
	this->mCompls[3].level = "ERROR";
}

void Harl::complain(std::string level)
{
	Ecompl index = findIndex(level);

	switch(index)
	{
		case E_DEBUG:
			debug();
			std::cout << std::endl;
			// fall through
		case E_INFO:
			info();
			std::cout << std::endl;
			// fall through
		case E_WARNING:
			warning();
			std::cout << std::endl;
			// fall through
		case E_ERROR:
			error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
