//
// Created by nsassenb on 4/10/24.
//
#include "easyfind.hpp"
#include <iostream>

struct Test
{
	std::string	m_owner;
	int			m_iMone;

	Test(){}
	Test(int i)
	{
		m_owner = "NPC";
		m_iMone = i;
	}

	bool operator<(const Test& other) const
	{
		return (m_iMone < other.m_iMone);
	}

	bool operator==(const Test& other) const
	{
		return (m_iMone == other.m_iMone);
	}
};

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
		std::cout << "Found: " << find << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<Test> struc = std::vector<Test>();
	for (size_t i = 0; i < 10; i++)
	{
		struc.push_back(Test(i));
	}

	Test	who(2);
	try
	{
		who = easyfind(struc, who);
		std::cout << who.m_owner << " " << who.m_iMone << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
	return (0);
}
