#include "RPN.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	RPN	r;
	if (argc != 2)
	{
		std::cerr << "Invalid args!" << std::endl;
		return (1);
	}
	try 
	{
		r.doRpn(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
