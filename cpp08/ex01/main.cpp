#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 10

int main()
{
	Span sp = Span(MAX_SIZE);
	std::srand(std::time(NULL));
	for (std::size_t i = 0; i < MAX_SIZE - 1; i++)
	{
		sp.addNumber(i);
	}
	
	Span cpy(sp);
	sp.addNumber(-1);
	cpy.addNumber(444);

	std::cout << "Shortest: " << sp.shortestSpan() << " | " << cpy.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << " | " << cpy.longestSpan() << std::endl;

	return 0;
}
