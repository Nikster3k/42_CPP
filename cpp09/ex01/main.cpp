#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	RPN	r;
	if (argc != 2)
	{
		std::cerr << "Invalid args!" << std::endl;
		return (1);
	}
	r.doRpn(argv[1]);
}
