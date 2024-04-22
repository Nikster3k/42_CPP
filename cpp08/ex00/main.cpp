#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <cstdlib>

void	vector_const_test(const std::vector<int>& t)
{
	std::cout << "Found: " << *easyfind(t, 5) << std::endl;
}

int	main(void)
{
	std::vector<int> wow = std::vector<int>();

	for (int i = 0; i < 10; ++i) {
		wow.push_back(i);
	}
	wow.at(4) = 42;
	for (size_t i = 0; i < wow.size(); i++)
	{
		std::cout << wow.at(i) << ", ";
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << "Found: " << *easyfind(wow, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		vector_const_test(wow);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	try
	{
		std::cout << "Found: " << *easyfind(std::string("Hello world!"), '!') << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::list<int> lst;

	for (size_t i = 0; i < 1000; i++)
	{
		lst.push_back(std::rand());
	}
	
	try
	{
		std::cout << "Found: " << *easyfind(lst, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
