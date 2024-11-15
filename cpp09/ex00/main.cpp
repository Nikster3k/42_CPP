#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	BitcoinExchange	bx;

	if (argc != 2)
	{
		std::cerr << "Error: required one argument." << std::endl;
		return (1);
	}
	if (!bx.loadCsv("data.csv"))
		return (1);
	bx.makeExchange(argv[1]);

}
