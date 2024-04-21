#include "Span.hpp"
#include <iostream>

#define MAX_SIZE 100000

int main()
{
	Span sp = Span(MAX_SIZE);
	try
	{
		sp.fillSpanRand();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span cpy(2);
	try
	{
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
