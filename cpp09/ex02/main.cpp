#include "PmergeMe.hpp"


int	main(int argc, char **argv)
{
	std::string inputstr;

	if (argc < 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; ++i) {
		inputstr += argv[i];
		inputstr += " ";
	}
	try 
	{
		PmergeMeVector(inputstr);
		PmergeMeDeque(inputstr);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
