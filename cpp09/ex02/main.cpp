#include "PmergeMe.hpp"
#include <ctime>
#include <exception>
#include <ctime>
#include <cstdio>
#include <cstdlib>

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
		std::time_t start;
		std::time_t end;
		std::time(&start);
		PmergeMeVector(inputstr);
		std::time(&end);
		std::cout << end - start << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
