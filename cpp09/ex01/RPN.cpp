#include "RPN.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

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

void	RPN::doRpn(const std::string& a_str)
{
	if (a_str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw (std::runtime_error("Error: non valid characters."));
	std::size_t	i = 0;
	while (i < a_str.length())
	{
		i = a_str.find_first_of("0123456789+-*/", i);
		if (i == std::string::npos)
			break;
		if (i + 1 < a_str.length() && a_str.at(i + 1) != ' ')
			throw (std::runtime_error("Error: invalid spacing."));
		addValue(a_str.at(i++));
	}
	if (m_calcs.size() != 1)
		throw (std::runtime_error("Error: missing operators"));
	std::cout << m_calcs.top() << std::endl;
}

void	RPN::addValue(char a_char)
{
	if (std::isdigit(a_char))
		m_calcs.push(a_char - '0');
	else
	{
		if (m_calcs.size() < 2)
			throw (std::runtime_error("Error: operation with too few numbers."));
		if (a_char == '*')
		{
			long a = m_calcs.top();
			m_calcs.pop();
			long b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(checkOverflow(b * a));
		}
		else if (a_char == '+')
		{
			long a = m_calcs.top();
			m_calcs.pop();
			long b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(checkOverflow(b + a));
		}
		else if (a_char == '-')
		{
			long a = m_calcs.top();
			m_calcs.pop();
			long b = m_calcs.top();
			m_calcs.pop();
			m_calcs.push(checkOverflow(b - a));
		}
		else if (a_char == '/')
		{
			long a = m_calcs.top();
			m_calcs.pop();
			long b = m_calcs.top();
			m_calcs.pop();
			if (a == 0)
				throw(std::runtime_error("Error: division by 0 not possible"));
			m_calcs.push(checkOverflow(b / a));
		}
	}
}

int	RPN::checkOverflow(long a_val) const
{
	if (a_val > std::numeric_limits<int>::max())
		throw(std::runtime_error("Error: calculation overflows"));
	return (a_val);
}
