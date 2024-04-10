#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int> iarr(10);

	iarr[1] = 10;
	for (std::size_t i = 0; i < iarr.size(); i++)
	{
		iarr[i] = i;
	}

	Array<int> other = Array<int>(10);

	std::cout << "size " << other.size() << std::endl;
	other = iarr;
	for (size_t i = 0; i < other.size(); i++)
	{
		other[i] = 42;
	}

	Array<int> overload(other);
	overload[3] = 10000000;

	for (size_t i = 0; i < other.size(); i++)
	{
		std::cout << "original: [ " << iarr[i] << " ], copy: [ " << other[i] << " ], overload: [ " << overload[i] << " ]" << std::endl;
	}

	try
	{
		std::cout << "Accessing at index 10 size is " << iarr.size() << std::endl;
		iarr[10];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Accessing at index -10 size is " << iarr.size() << std::endl;
		iarr[-10];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Accessing at index 2342 size is " << iarr.size() << std::endl;
		iarr[2342];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
