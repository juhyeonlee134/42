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

Harl::Harl()
{
	this->mLevel[0] = "DEBUG";
	this->mLevel[1] = "INFO";
	this->mLevel[2] = "WARNING";
	this->mLevel[3] = "ERROR";

	this->mCompl[0] = &Harl::debug;
	this->mCompl[1] = &Harl::info;
	this->mCompl[2] = &Harl::warning;
	this->mCompl[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->mLevel[i])
		{
			(this->*mCompl[i])();
			return;
		}
	}
	std::cerr << "Error: invalid level" << std::endl;
}