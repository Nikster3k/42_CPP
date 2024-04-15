#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>

void	vector_const_test(const std::vector<int>& t)
{
	std::cout << "Found at: " << easyfind(t, 5) << std::endl;
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
	
	int find;
	try
	{
		find = easyfind(wow, 42);
		std::cout << "Found at: " << find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	vector_const_test(wow);

	try
	{
		std::cout << "Found at: " << easyfind(std::string("Hello world!"), 32) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
