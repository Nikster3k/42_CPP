#include "iter.hpp"

void printchar(char& a)
{
	std::cout << static_cast<char>(toupper(a)) << std::endl;
}

int	main(void)
{
	char msg[] = "Hello world!";

	iter(msg, 2, printchar);
}
