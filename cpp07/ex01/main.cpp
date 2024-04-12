#include "iter.hpp"

void printchar(char& a)
{
	std::cout << static_cast<char>(toupper(a)) << std::endl;
}

void multi(const int& a)
{
	std::cout << a * 2 << std::endl;
}

int	main(void)
{
	char msg[] = "Hello world!";
	int const	vals[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	iter(&vals[0], 10, multi);
	iter(msg, 2, printchar);
	return (0);
}
