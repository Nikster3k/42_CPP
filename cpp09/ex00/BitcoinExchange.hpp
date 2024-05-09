#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class BitcoinExchange
{
private:
	std::map<std::string, double>	m_exchangeData;
	bool	printExchangeRate(std::string& a_input);
	bool	checkValidDatabase(const std::string& a_line, int a_lineIdx, const std::string& a_fileName) const;
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool	loadCsv(std::string a_fileName);
	void	makeExchange(std::string a_fileName);
};

#endif // !BITCOINEXCHANGE_H
