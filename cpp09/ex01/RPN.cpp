#include "RPN.hpp"
#include <cstddef>
#include <iostream>

RPN::RPN(void) : m_calcs() {}

RPN::RPN(const RPN& other) : m_calcs(other.m_calcs) {}

RPN::~RPN(void) {}

RPN& RPN::operator=(const RPN& other) 
{
	if (this != &other)
	{
		m_calcs = std::stack<int>(other.m_calcs);
	}
	return (*this);
}

bool	RPN::doRpn(const std::string& a_str)
{
	if (a_str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
	{
		std::cerr << "Error: non valid characters." << std::endl;
		return (false);
	}
	int	i = 0;
	int	previ = -1;
	while (i < static_cast<int>(a_str.length()))
	{
		std::cout << i << " " << previ << std::endl;
		if (i - previ < 2)
		{
			std::cerr << "Error: non valid number." << std::endl;
			std::cout << i << " " << previ << std::endl;
			return (false);
		}
		i = a_str.find_first_not_of(" ", i + 1);
		addValue(a_str.at(i));
		previ = i;
	}
	if (m_calcs.size() != 1)
	{
		std::cerr << "Error: missing to few operators" << std::endl;
		return (false);
	}
	std::cout << "Result: " << m_calcs.top() << std::endl;
	return (true);
}

bool	RPN::addValue(char a_char)
{
	if (std::isdigit(a_char))
		m_calcs.push(a_char - '0');
	else
	{
		if (m_calcs.size() < 2)
		{
			std::cerr << "Invalid" << std::endl;
			return (false);
		}
		if (a_char == '*')
		{
			int a = m_calcs.top();
			m_calcs.pop();
			int b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(a * b);
		}
		else if (a_char == '+')
		{
			int a = m_calcs.top();
			m_calcs.pop();
			int b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(a + b);
		}
		else if (a_char == '-')
		{
			int a = m_calcs.top();
			m_calcs.pop();
			int b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(a - b);
		}
		else if (a_char == '/')
		{
			int a = m_calcs.top();
			m_calcs.pop();
			int b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(a / b);
		}
	}
	return (true);
}
