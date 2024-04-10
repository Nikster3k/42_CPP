#include "Span.hpp"

Span::Span(unsigned int N)
{
	m_data = new int[N];
	m_max = N;
	m_top = 0;
}

Span::Span(const Span& other)
{
	m_data = new int[other.m_max];
	m_max = other.m_max;
	m_top = other.m_top;
}

Span::~Span()
{
	delete[] m_data;
}

void	Span::addNumber(int a_val)
{
	if (m_top >= m_max)
		throw (SpanFullException());
	m_data[m_top++] = a_val;
}

static int	getDifference(int lhs, int rhs)
{
	return (lhs < rhs ? rhs - lhs : lhs - rhs);
}

int	Span::shortestSpan(void)
{
	int	smallest = std::numeric_limits<int>().max();
	if (m_top < 2)
		throw (SpanNotPossible());
	for (std::size_t i = 0; i < m_top; ++i)
	{
		for (std::size_t n = i + 1; n < m_top; ++n)
		{
			if (getDifference(m_data[i], m_data[n]) < smallest)
			{
				smallest = getDifference(m_data[i], m_data[n]);
			}
		}
	}
	return (smallest);
}

int	Span::longestSpan(void)
{
	int	biggest = std::numeric_limits<int>().min();
	if (m_top < 2)
		throw (SpanNotPossible());
	for (std::size_t i = 0; i < m_top; ++i)
	{
		for (std::size_t n = i + 1; n < m_top; ++n)
		{
			if (getDifference(m_data[i], m_data[n]) > biggest)
			{
				biggest = getDifference(m_data[i], m_data[n]);
			}
		}
	}
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
