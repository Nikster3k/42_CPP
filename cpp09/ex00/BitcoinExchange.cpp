#include "BitcoinExchange.hpp"

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

// checks if date is in valid format
// checks if any other chars than string allowed are in the a_str.
// Checks for hyphen at idx: 4, 7
// YYYY: any 4 digit number
// MM: 1-12
// DD: 1-31
static	bool	checkValidDate(const std::string& a_str, const std::string& allowed)
{
	static int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::size_t	hyphen_pos = a_str.find('-');
	
	if (a_str.find_first_not_of(allowed) != std::string::npos || hyphen_pos != 4)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (false);
	}
	// int year = std::atoi(a_str.substr(0, hyphen_pos + 1).c_str());
	// if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	// 	std::cout << "schaltjahr\n";

	int month = std::atoi(a_str.substr(hyphen_pos + 1).c_str());
	if (month < 1 || month > 12 || (hyphen_pos = a_str.find('-', hyphen_pos + 1)) != 7)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (false);
	}

	int day = std::atoi(a_str.substr(hyphen_pos + 1).c_str());
	if (day < 1 || day > days_in_months[month - 1])
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkValidDatabase(const std::string& a_line, int a_lineIdx, const std::string& a_fileName) const
{
	std::size_t		commapos;
	commapos = a_line.find(',');
	if (commapos == std::string::npos)
	{
		std::cerr << "No comma on line: " << a_lineIdx << ", of file: " << a_fileName << std::endl;
		return (false);
	}
	if (!checkValidDate(a_line, "0123456789,.-"))
	{
		return (false);
	}
	if (commapos == a_line.length() - 1)
	{
		std::cerr << "No value after date at: " << a_lineIdx << ", of file: " << a_fileName << std::endl;
		return (false);
	}
	if (a_line.find_first_not_of("0123456789,.-") != std::string::npos)
	{
		std::cerr << "Not allowed character on line: " << a_lineIdx << ", of file: " << a_fileName << std::endl;
		return (false);
	}
	if (a_line.find_first_not_of("0123456789.", commapos + 1) != std::string::npos)
	{
		std::cerr << "Error in value on line: " << a_lineIdx << ", of file: " << a_fileName << std::endl;
		return (false);
	}
	return (true);
}

/**
 * Return value from input after the separator position
 * - checks if value has dot and is at same position
 * - checks if dot is at correct position (after first number)
 * - checks if value is in range of 0-1000
 * @param a_str string with date and value 
 * @param a_seperator_pos pos where parsing number starts
 * @param a_clamp if number over 1000 is an error, default false
 * @return converted value to double, or -1 on error
 */
static float	getValue(const std::string& a_str, const std::size_t a_seperator_pos, bool a_clamp = false)
{
	float	value = 0;
	std::size_t	dot_pos;

	if (a_seperator_pos == std::string::npos || (dot_pos = a_str.find('.', a_seperator_pos)) != a_str.find_last_of('.') 
		|| (dot_pos != std::string::npos && dot_pos < a_str.find_first_of("0123456789", a_seperator_pos) && dot_pos != a_str.length() - 1)
		|| a_str.find_first_not_of("0123456789.", a_seperator_pos) != std::string::npos)
	{
		std::cerr << "Error: bad input => " << a_str << std::endl;
		return (-1);
	}
	value = std::strtod(a_str.substr(a_seperator_pos).c_str(), NULL);
	if (value < 0 || (a_clamp && value > 1000))
	{
		std::cerr << "Error: " << (value < 0 ? "not a positive number." : "too large a number.") << std::endl;
		return (-1);
	}
	return (value);
}

//loads Csv into m_exchangeData, also:
// - checking if date is in correct format
// - checking for comma seperator
// - checking for value after comma
bool	BitcoinExchange::loadCsv(std::string a_fileName)
{
	std::ifstream	input;
	std::string		line;
	bool			is_success = true;

	input.open(a_fileName.c_str());
	if (!input.is_open() || !input.good())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}

	std::getline(input, line); //removes first line. Change
	if (line == "date,exchange_rate")
	{
		for (int i = 2; std::getline(input, line); ++i)
		{
			if (!checkValidDatabase(line, i, a_fileName))
			{
				is_success = false;
				break;
			}
			std::size_t commapos = line.find(',');
			float value = getValue(line, commapos + 1);
			if (value == -1)
			{
				std::cerr << "Error in value on line: " << i << ", of file: " << a_fileName << std::endl;
				is_success = false;
				break;
			}
			m_exchangeData[line.substr(0, commapos)] = value;
		}
	}
	else
	{
		std::cerr << "Input wrong format => \"" << line << "\"" << std::endl;
		is_success = false;
	}
	input.close();
	if (m_exchangeData.size() == 0)
	{
		std::cerr << "Database empty!" << std::endl;
		return (false);
	}
	return (is_success);
}

//prints exchange rate in given format
// - checks valid date format
// - checks for correct seperator position and thus preceding space
// - finds closest date from m_exchangeData and prints in given format
bool	BitcoinExchange::printExchangeRate(std::string& a_line)
{
	std::size_t	pipe_pos = -1;
	if (!checkValidDate(a_line, "0123456789|. -"))
		return (false);

	pipe_pos = a_line.find('|');
	if (pipe_pos != 11 || pipe_pos >= a_line.length())
	{
		std::cerr << "Error: bad input => " << a_line << std::endl;
		return (false);
	}

	std::string	date = a_line.substr(0, pipe_pos - 1);
	std::map<std::string, double>::iterator found_it = m_exchangeData.lower_bound(date);
	float value = getValue(a_line, pipe_pos + 2, true);
	if (value < 0)
		return (false);
	if (date < m_exchangeData.begin()->first)
	{
		std::cerr << "Error: input date is too old => " << a_line << std::endl;
		return (false);
	}
	if (found_it != m_exchangeData.begin() && date != found_it->first)
		found_it--;
	if (found_it != m_exchangeData.end())
		std::cout << found_it->first << " => " << value << " => " << found_it->second * value<< std::endl;
	return (true);
}

//loads input file with dates and corresponding values
void	BitcoinExchange::makeExchange(std::string a_fileName)
{
	std::ifstream	input;
	std::string		line;

	input.open(a_fileName.c_str());
	if (!input.is_open() || !input.good())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::getline(input, line);
	if (line == "date | value")
	{
		for (int i = 1; std::getline(input, line); ++i)
		{
			printExchangeRate(line);
		}
	}
	else
		std::cerr << "Input wrong format => " << line << std::endl;
	input.close();
}
