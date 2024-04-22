#ifndef SPAN_H
# define SPAN_H

#include <exception>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>

class Span
{
private:
	unsigned int		m_max;
	std::vector<int>	m_data;
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int a_val);
	long	shortestSpan(void);
	long	longestSpan(void);
	void	fillSpanRand(void);
	void	addRange(std::vector<int>::const_iterator a_itBegin, std::vector<int>::const_iterator a_itEnd);

	class SpanFull : public std::exception
	{
	public:
		const char*	what() const throw();
	};

	class SpanNotPossible : public std::exception
	{
	public:
		const char*	what() const throw();
	};
};

#endif // !SPAN_H
