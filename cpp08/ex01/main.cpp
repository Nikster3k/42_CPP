#include "Span.hpp"
#include <iostream>

#define MAX_SIZE 100000

std::vector<int>	createRandomArray(std::size_t a_size)
{
	std::vector<int>	data;
	std::srand(std::time(NULL));
	data.resize(a_size);
	std::generate(data.begin(), data.end(), std::rand);
	return (data);
}

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
	
	try
	{
		std::cout << "Span1: shortest:" << sp.shortestSpan() << " | longest: " << sp.longestSpan() << std::endl;
		std::cout << "Span2: shortest:" << cpy.shortestSpan() << " | longest: " << cpy.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " <Exception: " << e.what() << ">\n";
	}

	Span ab(10);
	std::vector<int>	randVec = createRandomArray(10);
	// ab.addNumber(1);
	try
	{
		ab.addRange(randVec.begin(), randVec.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "shortest:" << ab.shortestSpan() << " | longest: " << ab.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " <Exception: " << e.what() << ">\n";
	}
	
	return 0;
}
