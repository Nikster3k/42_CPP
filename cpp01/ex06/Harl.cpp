#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!\n" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n	" << std::endl;
}

int	evalLevel(std::string level)
{
	const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (4);
}

void	Harl::complain(std::string level) const
{
	const harl_func funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int complain_lvl = evalLevel(level);

	if (complain_lvl == 4)
		std::cout << "Not a valid level" << std::endl;
	else
		(this->*(funcs[complain_lvl]))();
}
