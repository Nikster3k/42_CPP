#include "Span.hpp"

Span::Span(unsigned int N)
{
	m_data = std::vector<int>();
	m_max = N;
	m_longSpan = false;
	m_shortSpan = false;
}

Span::Span(const Span& other)
{
	m_data = std::vector<int>(other.m_data);
	m_max = other.m_max;
	m_longSpan = other.m_longSpan;
	m_shortSpan = other.m_shortSpan;
}

Span&	Span::operator= (const Span& other)
{
	if (this != &other)
	{
		m_data = std::vector<int>(other.m_data);
		m_max = other.m_max;
		m_longSpan = other.m_longSpan;
		m_shortSpan = other.m_shortSpan;
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
	m_shortSpan = m_longSpan = false;
	m_data.push_back(a_val);
	// std::sort(m_data.begin(), m_data.end());
}

static int	getDifference(int lhs, int rhs)
{
	return (lhs < rhs ? rhs - lhs : lhs - rhs);
}

int	Span::shortestSpan(void)
{
	static int	smallest = std::numeric_limits<int>().max();
	if (m_shortSpan)
		return (smallest);
	if (m_data.size() < 2)
		throw (SpanNotPossible());
	for (std::size_t i = 0; i < m_data.size(); ++i)
	{
		for (std::size_t n = i + 1; n < m_data.size(); ++n)
		{
			if (getDifference(m_data[i], m_data[n]) < smallest)
			{
				smallest = getDifference(m_data[i], m_data[n]);
			}
		}
	}
	m_shortSpan = true;
	return (smallest);
}

int	Span::longestSpan(void)
{
	static int	biggest = std::numeric_limits<int>().min();
	if (m_longSpan)
		return (biggest);
	if (m_data.size() < 2)
		throw (SpanNotPossible());
	for (std::size_t i = 0; i < m_data.size(); ++i)
	{
		for (std::size_t n = i + 1; n < m_data.size(); ++n)
		{
			if (getDifference(m_data[i], m_data[n]) > biggest)
			{
				biggest = getDifference(m_data[i], m_data[n]);
			}
		}
	}
	m_longSpan = true;
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
