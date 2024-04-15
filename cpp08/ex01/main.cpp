#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 100000

int main()
{
	Span sp = Span(MAX_SIZE);
	std::srand(std::time(NULL));
	try
	{
		for (std::size_t i = 0; i < MAX_SIZE - 2; i++)
		{
			sp.addNumber(std::rand());
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span cpy(sp);
	try
	{
		sp.addNumber(-1);
		cpy.addNumber(std::numeric_limits<int>().min());
		cpy.addNumber(std::numeric_limits<int>().max());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Span1: shortest:" << sp.shortestSpan() << " | longest: " << sp.longestSpan() << std::endl;
		std::cout << "Span2: shortest:" << cpy.shortestSpan() << " | longest: " << cpy.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " <Exception: " << e.what() << ">\n";
	}
	
	return 0;
}
