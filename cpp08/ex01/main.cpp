#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Span sp = Span(100000);
	std::srand(std::time(NULL));
	for (std::size_t i = 0; i < 100000; i++)
	{
		sp.addNumber(std::rand());
	}
	
	std::cout << "Start spans" << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
