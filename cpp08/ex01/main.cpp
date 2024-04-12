#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 10000

int main()
{
	Span sp = Span(MAX_SIZE);
	std::srand(std::time(NULL));
	for (std::size_t i = 0; i < MAX_SIZE - 1; i++)
	{
		sp.addNumber(std::rand());
	}
	std::cout << "Start spans" << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	sp.addNumber(5);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
