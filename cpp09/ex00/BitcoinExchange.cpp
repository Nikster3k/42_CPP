#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(void) : m_exchangeData() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m_exchangeData(other.m_exchangeData) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		m_exchangeData = std::map<std::string, double>(other.m_exchangeData);
	}
	return (*this);
}

static	bool	checkValidDate(const std::string& a_str, const std::string& allowed)
{
	std::size_t	hyphen_pos = a_str.find('-');
	int			curr_num = 0;
			
	if (a_str.find_first_not_of(allowed) != std::string::npos || hyphen_pos != 4)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (false);
	}
	curr_num = std::atoi(a_str.substr(hyphen_pos + 1).c_str());
	if (curr_num < 0 || curr_num > 12 || (hyphen_pos = a_str.find('-', hyphen_pos + 1)) != 7)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (false);
	}
	curr_num = std::atoi(a_str.substr(hyphen_pos + 1).c_str());
	if (curr_num < 0 || curr_num > 31)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::loadCsv(std::string a_fileName)
{
	std::ifstream	input;
	std::string		line;
	std::size_t		commapos;
	bool			is_success = true;

	input.open(a_fileName.c_str());
	if (!input.is_open() || !input.good())
	{
		std::cerr << "File bad" << std::endl;
		return (false);
	}
	std::getline(input, line);
	for (int i = 1; std::getline(input, line); ++i)
	{
		commapos = line.find(',');
		if (!checkValidDate(line, "0123456789,.-"))
			break;
		if (commapos == std::string::npos)
		{
			std::cerr << "No comma on line: " << i << ", of file: " << a_fileName << std::endl;
			is_success = false;
			break;
		}
		if (commapos == line.length() - 1)
		{
			std::cerr << "No value after date at: " << i << ", of file: " << a_fileName << std::endl;
			is_success = false;
			break;
		}
		if (line.find_first_not_of("0123456789,.-") != std::string::npos)
		{
			std::cerr << "Not allowed character on line: " << i << ", of file: " << a_fileName << std::endl;
			is_success = false;
			break;
		}
		m_exchangeData[line.substr(0, commapos)] = std::strtod(line.substr(commapos + 1).c_str(), NULL);
	}
	input.close();
	return (is_success);
}

static float	getMoneyValue(const std::string& a_str)
{
	std::size_t	pipepos = a_str.find('|');
	long		value = 0;
	if (pipepos == std::string::npos || a_str.find_first_of("-+0123456789", pipepos) != 13)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (-1);
	}
	value = std::strtod(a_str.substr(pipepos + 1).c_str(), NULL);
	if (value > 1000 || value < 0)
	{
		std::cerr << "Error: " << (value < 0 ? "not a positive number." : "too large a number.") << std::endl;
		return (-1);
	}
	return (value);
}

bool	BitcoinExchange::printExchangeRate(std::string& a_line)
{
	if (!checkValidDate(a_line, "0123456789|. -"))
		return (false);
	if (a_line.find('|') != 11)
	{
		std::cerr << "Error: bad input => " << a_line << std::endl;
		return (false);
	}
	std::map<std::string, double>::iterator found_it = m_exchangeData.lower_bound(a_line);
	float money = getMoneyValue(a_line);
	if (money < 0)
		return (false);
	if (found_it != m_exchangeData.begin())
		found_it--;
	std::cout << found_it->first << " => " << money << " => " << found_it->second * money<< std::endl;
	// std::cout << a_line.substr(hyphen_pos + 1) << std::endl;
	return (true);
}

void	BitcoinExchange::makeExchange(std::string a_fileName)
{
	std::ifstream	input;
	std::string		line;

	input.open(a_fileName.c_str());
	if (!input.is_open() || !input.good())
	{
		std::cerr << "File bad" << std::endl;
		return ;
	}
	// std::getline(input, line);
	for (int i = 1; std::getline(input, line); ++i)
	{
		// if (pipepos == std::string::npos)
		// 	std::cerr << "No seperator on line: " << i << ", of file: " << a_fileName << std::endl;
		// if (pipepos == line.length() - 1 || line.find_first_of("0123456789") == std::string::npos)
		// 	std::cerr << "No value after date at: " << i << ", of file: " << a_fileName << std::endl;
		printExchangeRate(line);
	}
	input.close();
}
