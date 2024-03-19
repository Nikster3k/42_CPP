#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) const
{
	std::cout << "Debug log!" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "Info log!" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "Warning log!" << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "Error log!" << std::endl;
}

int	evalLevel(std::string& level)
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
