//
// Created by nsassenb on 4/10/24.
//
#include "easyfind.hpp"
#include <iostream>


int	main(void)
{
	std::vector<int> wow = std::vector<int>();

	for (int i = 0; i < 10; ++i) {
		wow.push_back(i);
	}
	wow.at(4) = 42;
	int	tofind = 42;
	for (size_t i = 0; i < wow.size(); i++)
	{
		std::cout << wow.at(i) << ", ";
	}
	
	easyfind(wow, tofind);
	return (0);
}
