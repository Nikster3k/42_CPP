#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "Debug log!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info log!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning log!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error log!" << std::endl;
}

level	evalLevel(std::string& level)
{
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (NONE);
}

void	Harl::complain(std::string level)
{
	std::cout << level << &Harl::info << std::endl;
}