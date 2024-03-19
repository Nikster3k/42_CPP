#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl	h;

	if (argc < 2)
	{
		std::cout << "Need 1 argument!" << std::endl;
		return (1);
	}
	h = Harl();
	
	switch (evalLevel(argv[1]))
	{
	case 0:
		h.complain("DEBUG");
	case 1:
		h.complain("INFO");
	case 2:
		h.complain("WARNING");
	case 3:
		h.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
