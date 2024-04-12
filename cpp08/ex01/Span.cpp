#include "Span.hpp"

Span::Span(unsigned int N)
{
	m_data = std::vector<int>();
	m_max = N;
}

Span::Span(const Span& other)
{
	m_data = std::vector<int>(other.m_data);
	m_max = other.m_max;
}

Span&	Span::operator= (const Span& other)
{
	if (this != &other)
	{
		m_data = std::vector<int>(other.m_data);
		m_max = other.m_max;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int a_val)
{
	if (m_data.size() >= m_max)
		throw (SpanFullException());
	m_data.push_back(a_val);
}

int	Span::shortestSpan(void)
{
	int	smallest = std::numeric_limits<int>().max();
	if (m_data.size() < 2)
		throw (SpanNotPossible());
	std::sort(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < m_data.size() - 1; ++i)
	{
		if (m_data[i + 1] - m_data[i] < smallest)
			smallest = m_data[i + 1] - m_data[i];
	}
	return (smallest);
}
#include <iostream>
int	Span::longestSpan(void)
{
	int	biggest = std::numeric_limits<int>().min();
	if (m_data.size() < 2)
		throw (SpanNotPossible());
	std::sort(m_data.begin(), m_data.end());
	biggest = m_data.at(m_data.size() - 1) - m_data.at(0);
	return (biggest);
}

const char*	Span::SpanFullException::what() const throw()
{
	return ("Span is full, adding more numbers not possible.");
}

const char*	Span::SpanNotPossible::what() const throw()
{
	return ("Less than two values in Span, span not possible.");
}
