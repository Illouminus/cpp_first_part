#include "Harl.hpp"
#include <iostream>

// Конструктор
Harl::Harl(void) {}

// Реализация методов с выводом соответствующих сообщений

void Harl::debug(void) const
{
	std::cout << "[DEBUG]\n"
				 << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void) const
{
	std::cout << "[INFO]\n"
				 << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "[WARNING]\n"
				 << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) const
{
	std::cout << "[ERROR]\n"
				 << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) const
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
		i++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}