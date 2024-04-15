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

Span::~Span() {}

void	Span::addNumber(int a_val)
{
	if (m_data.size() >= m_max)
		throw (SpanFull());
	m_data.push_back(a_val);
}

long	Span::shortestSpan(void)
{
	long	smallest = std::numeric_limits<int>().max();
	if (m_data.size() < 2)
		throw (SpanNotPossible());
	std::sort(m_data.begin(), m_data.end());
	for (std::size_t i = 0; i < m_data.size() - 1; ++i)
	{
		if (static_cast<long>(m_data.at(i + 1)) - m_data.at(i) < smallest)
			smallest = static_cast<long>(m_data.at(i + 1)) - m_data.at(i);
	}
	return (smallest);
}

long	Span::longestSpan(void)
{
	long	biggest = std::numeric_limits<int>().min();
	if (m_data.size() < 2)
		throw (SpanNotPossible());
	std::sort(m_data.begin(), m_data.end());
	// std::cout << m_data.at(m_data.size() - 1) << " " << m_data.at(0) << std::endl;
	biggest = static_cast<long>(m_data.at(m_data.size() - 1)) - m_data.at(0);
	return (biggest);
}

const char*	Span::SpanFull::what() const throw()
{
	return ("Span is full, adding more numbers not possible.");
}

const char*	Span::SpanNotPossible::what() const throw()
{
	return ("Less than two values in Span, span not possible.");
}
